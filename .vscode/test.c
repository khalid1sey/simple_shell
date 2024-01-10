#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

void display_prompt() {
    printf("$ ");
    fflush(stdout);
}

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            exit(WEXITSTATUS(status));
        } else 
        {
            exit(0);
        }
    }
}

void handle_input(char *input) {
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input into command and arguments
    char *command = strtok(input, " ");
    if (command == NULL) {
        return;  // Empty input, ignore
    }

    char *args[MAX_ARGS];
    int arg_count = 0;

    args[arg_count++] = command;

    char *arg = strtok(NULL, " ");
    while (arg != NULL) {
        args[arg_count++] = arg;
        if (arg_count >= MAX_ARGS - 1) {
            break;  // Reached the maximum number of arguments
        }
        arg = strtok(NULL, " ");
    }

    args[arg_count] = NULL;  // Set the last element to NULL for execvp

    if (strcmp(command, "exit") == 0) {
        exit(0);  // Exit the shell
    } else if (strcmp(command, "env") == 0) {
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
    } else {
        execute_command(args);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        display_prompt();

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;  // Handle end of file (Ctrl+D)
        }

        handle_input(input);
    }

    return 0;
}