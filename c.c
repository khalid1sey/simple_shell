#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

void prompt(char *cmd);
int check_cmd_exists(const char *cmd, const char *path);
void executecmd(char *cmd, int comcounter);

int main(void)
{
    char cmd[MAX_CMD_LEN];
    int comcounter = 0;

    while (1)
    {
        prompt(cmd);
        cmd[strcspn(cmd, "\n")] = '\0';

        comcounter++;
        executecmd(cmd, comcounter);
    }
    return 0;
}

void prompt(char *cmd)
{
    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);
}

int check_cmd_exists(const char *cmd, const char *path)
{
    char commandPath[MAX_CMD_LEN];
    snprintf(commandPath, sizeof(commandPath), "%s/%s", path, cmd);

    struct stat st;
    if (stat(commandPath, &st) == 0)
    {
        if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
        {
            return (0);
        }
    }

    return (-1);
}

void executecmd(char *cmd, int comcounter)
{
    char *args[MAX_ARGS];
    int argscount = 0;
    char *path = getenv("PATH");
    char *pathToken = strtok(path, ":");

    int commandFound = 0;

    char *token = strtok(cmd, " ");
    while (token != NULL && argscount < MAX_ARGS - 1)
    {
        args[argscount] = token;
        argscount++;
        token = strtok(NULL, " ");
    }
    args[argscount] = NULL;

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        while (pathToken != NULL)
        {
            if (check_cmd_exists(args[0], pathToken) == 0)
            {
                commandFound = 1;
                char commandPath[MAX_CMD_LEN];
                snprintf(commandPath, sizeof(commandPath), "%s/%s", pathToken, args[0]);
                execv(commandPath, args);
                break;
            }
            pathToken = strtok(NULL, ":");
        }
        exit(1); // Exit if the command is not found
    }
    else
    {
        int status;
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "%s: %d: %s: not found\n", args[0], comcounter, strerror(WEXITSTATUS(status)));
        }
    }

    if (commandFound == 0)
    {
        fprintf(stderr, "%s: %d: command not found\n", args[0], comcounter);
    }
}