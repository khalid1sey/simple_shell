#include "main.h"

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
    int SS_BUILTINS = (sizeof(builtins) / sizeof(char *));
    char *path = getenv("PATH");

    for (i = 0; i < SS_BUILTINS; i++)
    {
        if(strcmp(args[0], builtins[i]) == 0)
        {
            (builtin_func[i])(args);
            return;
        }
    }
    
    printf("PATH: %s\n", path);
    if (access(args[0], X_OK) == 0)
    {
        
        if (child_pid == 0)
        {
            execvp(args[0], args);
            perror("Bash");
            exit(1);
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
    else
    {
        fprintf(stderr, "Command not found: %s\n", args[0]);
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