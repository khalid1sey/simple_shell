#include "shell.h"

struct builtin{
    char *name;
    int (*builtin_func_t)(char **args);
};

struct builtin builtins[] = {
    {"help", ss_help},
    {"exit", ss_exit},
    {"env", ss_env},
};

int SS_BUILTINS = (sizeof(builtins) / sizeof(struct builtin));


/**
 * main - entry point
 *
 * Return: void 0
 */

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    char *cmd;
    char **tokens;
    
    while (1)
    {
        cmd = prompt();
       
        tokens = kash_split_line(cmd);

        if (tokens[0] != NULL) {
            execute_cmd(tokens);
        }

        free(tokens);
        free(cmd);

    }
    return (0);
}

/**
 * prompt - reads lines from std input
 * 
 * return: lines entered
*/
char *prompt()
{
    char *cmd_line = NULL;
    size_t length = 0;
    ssize_t read;

    printf("$ ");

    read = getline(&cmd_line, &length, stdin);
    
    if(read == -1)
    {
        fprintf(stderr, "Error reading input\n");
        exit(1);
    }

    return(cmd_line);
}

void execute_cmd(char **args)
{
    int i = 0;
    pid_t child_pid = fork();
    /*char *path = getenv("PATH");*/

    for (i = 0; i < SS_BUILTINS; i++)
    {
        if(strcmp(args[0], builtins[i].name) == 0)
        {
            (builtins[i]).builtin_func_t(args);
            return;
        }
    }
    
    /*printf("PATH: %s\n", path);*/
    if (child_pid == 0)
    {
        char *command_path = resolve_command_path(args[0]);
        if (access(args[0], X_OK) == 0)
        {
            execv(command_path, args);
            perror("Bash");
            exit(1);
        }
        else
        {
            char *command_path = malloc(strlen(args[0]) + 6);
            sprintf(command_path, "/bin/%s", args[0]);
            execvp(command_path, args);
            free(command_path);
            // Command is not a file path
            fprintf(stderr, "Command not found: %s\n", args[0]);
            exit(1);
        }
    }
    else if (child_pid > 0)
    {
        int status;
        do
        {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
    {
        perror("Bash");
    }
}

char** kash_split_line(char *line) {
    int length = 0;
    int capacity = 16;
    char **tokens = malloc(capacity * sizeof(char*));

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    while (token != NULL) {
        tokens[length] = token;
        length++;

        if (length >= capacity) {
            capacity = (int) (capacity * 1.5);
            tokens = realloc(tokens, capacity * sizeof(char*));
        }

        token = strtok(NULL, delimiters);
    }

    tokens[length] = NULL;
    return tokens;
}


char *resolve_command_path(char *command) {
    char *path = getenv("PATH");
    char *token;
    char *path_copy = strdup(path);

    token = strtok(path_copy, ":");
    while (token != NULL) {
        char *command_path = malloc(strlen(token) + strlen(command) + 2);
        sprintf(command_path, "%s/%s", token, command);
        struct stat st;
        if (stat(command_path, &st) == 0 && (st.st_mode & S_IXUSR)) {
            free(path_copy);
            return command_path;
        }
        free(command_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}