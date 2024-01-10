#include "shell.h"
/**
 * prompt - prompts user to enter comand
 * Return: typed command
*/
char *prompt()
{
	char *cmd_line = NULL;
	size_t length = 0;
	ssize_t n_read;

	printf("$ ");
	n_read = getline(&cmd_line, &length, stdin);
	if (n_read == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (cmd_line);
}
