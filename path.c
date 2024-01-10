#include "shell.h"

/**
 * resolve_command_path - reads lines from std input
 * @command: command to look for
 * Return: lines entered
*/
char *resolve_command_path(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char *path_copy = strdup(path);
	struct stat st;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *command_path = malloc(strlen(token) + strlen(command) + 2);

		sprintf(command_path, "%s/%s", token, command);

		if (stat(command_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
