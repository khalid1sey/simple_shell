#include "main.h"

/**
 * main - entry point
 *
 * Return: void 0
 */
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
    return (0);
}

/**
 * prompt - displays prompt takes user input
 *
 * @cmd: the command user enters
 *
 * Return: 0 void
 */
void prompt(char *cmd)
{
    const char dollar[] = "$ ";
    
    write(1, dollar, sizeof(dollar) - 1);
    fgets(cmd, MAX_CMD_LEN, stdin);
}

/**
 * executecmd - execute the command user entered
 *    if executable cannot be found display error messages
 *
 * @cmd: the commmand user enters
 * @comcounter: counts everytime a command is executed
 *
 * Return: o void
 */
void executecmd(char *cmd, int comcounter)
{
    const char *args[MAX_ARGS];
	const char *path = getenv("PATH");
   
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        execle(path, args[0], NULL);
        exit(1);
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
}