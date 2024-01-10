#include "shell.h"

/**
 * search_cmd - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int search_cmd(char **args)
{
	if (!args[0])
		return (0);
	if (!strcmp(args[0], "exit"))
		ss_exit(args);
	else if (!strcmp(args[0], "env"))
		ss_env();
	else if (!strcmp(args[0], "cd"))
		ss_cd(args);
	else
		return (0);
	return (1);
}

/**
 * ss_cd - changes the current working directory of the shell
 * @args: array of arguments
 */
void ss_cd(char **args)
{
	char *dir = args[1];
	int ret;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}

/**
 * ss_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: Nothing.
 */
void ss_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}
	free_array(args);
	free_last_input();
	exit(status);
}

/**
 * ss_env - Prints all the environment variables.
 *
 * Return: void.
 */
int ss_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		puts(environ[i]);
		putchar('\n');
	}

	return (0);
}
