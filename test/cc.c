#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

void prompt();
int execute_command(const char *cmd, char *envp[]);
void print_environment(char *envp[]);

int main(int argc, char *argv[], char *envp[])
{
    char cmd[MAX_CMD_LEN];

    while (1)
    {
        prompt();
        if (fgets(cmd, sizeof(cmd), stdin) == NULL)
        {
            printf("\n");
            break; // Exit the loop on end of file (Ctrl+D)
        }

        cmd[strcspn(cmd, "\n")] = '\0'; // Remove the trailing newline character

        if (strlen(cmd) == 0)
        {
            continue; // Ignore empty commands
        }

        if (strcmp(cmd, "env") == 0)
        {
            print_environment(envp);
            continue;
        }

        if (execute_command(cmd, envp) != 0)
        {
            fprintf(stderr, "%s: command not found\n", cmd);
        }
    }

    return 0;
}

void prompt()
{
    printf("$ ");
    fflush(stdout);
}

int execute_command(const char *cmd, char *envp[])
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    int found_cmd = 0;
    char cmd_path[MAX_CMD_LEN];

    while (dir != NULL)
    {
        char cmd_path[MAX_CMD_LEN];
        snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, cmd);
        if (access(cmd_path, X_OK) == 0)
        {
            found_cmd = 1;
            break;
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);

    if (!found_cmd)
    {
        return -1; // Command not found
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        // Tokenize the command line into arguments
        char *args[MAX_ARGS + 1]; // +1 for the NULL terminator
        int i = 0;
        char *token = strtok((char *)cmd, " ");
        
        while (token != NULL && i < MAX_ARGS)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;

        execve(cmd_path, args, envp);
        exit(1); // Exit if exec fails
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        return status; // Return the exit status of the child process
    }
}

void print_environment(char *envp[])
{
    for (int i = 0; envp[i] != NULL; i++)
    {
        printf("%s\n", envp[i]);
    }
}