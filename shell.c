#include "shell.h"

/**
 * main - entry point
 * @argc: arguement counter
 * @envp: enviroment variables
 * Return: 0 on success
*/
int main(int argc __attribute__((unused)), char *envp[])
{
	char *cmd;
	char *args[10];

	while (1)
	{
		cmd = prompt();

		tokenize_cmd(cmd, args);
		execute_builtins(args, envp);

		free(cmd);
	}
	return (0);
}
