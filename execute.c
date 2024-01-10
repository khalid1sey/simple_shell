#include "shell.h"

/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t pid;
	int status = 0;
	char *cmd_path, *envp[2];

	if (argv == NULL || *argv == NULL)
		return (status);
	if (search_cmd(argv))
		return (status);

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == -1)
		perror(argv[0]), free_array(argv), free_last_input();
	if (pid == 0)
	{
		envp[0] = get_path();
		envp[1] = NULL;
		cmd_path = NULL;
		if (argv[0][0] != '/')
			cmd_path = search_path(argv[0]);
		if (cmd_path == NULL)
			cmd_path = argv[0];
		if (execve(cmd_path, argv, envp) == -1)
		{
			perror(argv[0]), free_array(argv), free_last_input();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
