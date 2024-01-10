#include "shell.h"

/**
 * main - implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *cmd;
	char **args;
	int status;

	do {
		cmd = read_cmd();
		if (!cmd || !*cmd)/* EOF detected, exit the loop */
			break;

		args = split_cmd(cmd);
		if (!args || !*args)
		{
			free(cmd);
			free_array(args);
			continue;
		}
		status = execute(args);
		free(cmd);
		free_array(args);

		/* Set status to 1 to continue the loop */
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}

/**
 * prompt - Print shell prompt to stdin stream.
 *
 * Return: void.
 */
void prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * free_array - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void free_array(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}
