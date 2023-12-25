#include "main.h"

/**
 * main - entry point
 * 
 * return - void 0
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
 * return: 0 void
*/
void prompt(char *cmd)
{
	const char dollar[] = "$ ";
	write(1, dollar ,sizeof(dollar) - 1);
	fgets(cmd, MAX_CMD_LEN, stdin);
}

/**
 * check_cmd_exists - checks if a command is available or not
 * 
 * @cmd: the command user enters
 * @path: path to look into commands
 * 
 * return: integer based number or status of exit code
*/
int check_cmd_exists(char *cmd, char *path)
{
	char commandPath[MAX_CMD_LEN];
	snprintf(commandPath, sizeof(commandPath), "%s/%s", path, cmd);

	return access(commandPath, X_OK);
}

/**
 * executecmd - execute the command user entered
 * 	if executable cannot be found display error messages
 * 
 * @cmd: the commmand user enters
 * @comcounter: counts everytime a command is executed
 * 
 * return: o void
*/
void executecmd(char *cmd,int comcounter)
{
	char *args[MAX_ARGS];
	int argscount = 0;
	char *path = getenv("PATH");
	char *pathToken = strtok(path, ":");
	int commandFound = 0;
	

	char *token = strtok(cmd, " ");
	while (token  != NULL && argscount < MAX_ARGS - 1)
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
			} else if (pid == 0)
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
				
				   exit(1);
				
				exit(0);
			} else
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
