#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 on success
*/
int main(void)
{
	char cmd[200];
	char *argv[2];
	char *envp[] = {NULL};
	int status;

	while (1)
	{
		printf("$ ");
		fgets(cmd, sizeof(cmd), stdin);

		cmd[strcspn(cmd, "\n")] = 0;

		if (strchr(cmd, ' ') == NULL)
		{
			argv[0] = cmd;
			argv[1] = NULL;

			status = execve(cmd, argv, envp);
			if (status == -1)
				perror(cmd);
		} else
			printf("%s: not a single-word cmd\n", cmd);
	}
	return (0);
}
