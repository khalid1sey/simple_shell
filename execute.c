#include "shell.h"
/**
 * execute_cmd - executes command
 * @args: arguments
 * @envp: enviroment variables
 * Return: 0 nothing
*/

void execute_cmd(char *args[], char *envp[])
{
	pid_t pid = fork();
	char *command = args[0];
	char *command_path = search_command(command, envp);
	int status, exit_status, signal_number;

	if (command_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", command);
		free(command_path);
		return;
	}
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execve(command_path, args, envp) == -1)
		{
			perror("excevp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				fprintf(stderr, "Command exited with status %d\n", exit_status);
		} else if (WIFSIGNALED(status))
		{
			signal_number = WTERMSIG(status);
			fprintf(stderr, "Command terminated with signal %d\n", signal_number);
		}
	}
}

/**
 * search_command - executes command
 * @command: arsguments
 * @envp: environments var
 * Return: 0 nothing
*/
char *search_command(char *command, char *envp[] __attribute__((unused)))
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char *command_path = malloc(strlen(dir) + strlen(command) + 2);

		sprintf(command_path, "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * execute_builtins - executes command
 * @args: arguments
 * @envp: environments var
 * Return: 0 nothing
*/
void execute_builtins(char *args[], char *envp[])
{
	char *command = args[0];

	if (strcmp(command, "exit") == 0)
		handle_exit();
	else if (strcmp(command, "cd") == 0)
		handle_cd(args);
	else if (strcmp(command, "env") == 0)
		handle_env(envp);
	else
		execute_cmd(args, envp);
}
