#include "shell.h"
/**
 * handle_exit - Handles the exit built-in command
 *
 * Return: No return value
 */
void handle_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * handle_cd - Handles the cd built-in command
 * @args: Array of command arguments
 *
 * Return: No return value
 */
void handle_cd(char *args[])
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("chdir");
		}
	}
}

/**
 * handle_env - Handles the env built-in command
 * @envp: Array of environment variables
 *
 * Return: No return value
 */
void handle_env(char *envp[])
{
	char **env = envp;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
