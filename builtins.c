#include "shell.h"

/**
 * ss_help - displays available commands
 *
 * @args: command entered
 * Return: 1 if used
*/
int ss_help(__attribute__((unused)) char **args)
{
	char *helptext =
	"Kash - the Kinda Aimless Shell. The following commands are available:\n";

	printf("%s", helptext);
	return (1);
}

/**
 * ss_exit - exits the shell when exit is entered
 *
 * @args: command enterd
 * Return: 0 on success
*/
int ss_exit(__attribute__((unused)) char **args)
{
	exit(0);
}

/**
 * ss_env - displays current environment
 *
 * @args: command enetred
 * Return: 1 on
*/
int ss_env(char **args)
{
	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	return (1);
}
