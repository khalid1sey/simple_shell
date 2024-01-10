#include "shell.h"

/**
 * tokenize_cmd - tokenizes command
 * @cmd: command
 * @args: arguments
 * Return: 0 nothing
*/
void tokenize_cmd(char *cmd, char *args[])
{
	char *token;
	int i;

	cmd[strcspn(cmd, "\n")] = 0;
	token = strtok(cmd, " ");
	i = 0;
	while (token != NULL && i < 20)
	{
		if (token[0] != '#')
			args[i++] = token;
		else
			break;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}
