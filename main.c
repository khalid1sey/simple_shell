#include "shell.h"


/**
 * main - entry point
 *
 * Return: void 0
 */

int main(void)
{
	char *cmd;
	char **tokens;

	while (1)
	{
		cmd = prompt();
		tokens = kash_split_line(cmd);

		if (tokens[0] != NULL)
			execute_cmd(tokens);

		free(tokens);
		free(cmd);
	}
	return (0);
}

/**
 * prompt - reads lines from std input
 *
 * Return: lines entered
*/
char *prompt()
{
	char *cmd_line = NULL;
	size_t length = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&cmd_line, &length, stdin);

	if (read == -1)
	{
		fprintf(stderr, "Error reading input\n");
		exit(1);
	}

	return (cmd_line);
}

/**
 * execute_builtin - reads lines from std input
 * @args: command to execute
 * Return: lines entered
*/
void execute_builtin(__attribute__((unused)) char **args)
{
	int i = 0;

	builtin_t builtins[] = {
	{"exit", ss_exit},
	{"env", ss_env},
	};

	for (i = 0; i < 2; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			(builtins[i]).builtin_func_t(args);
			return;
		}
	}
}

/**
 * execute_cmd - reads lines from std input
 * @args: command to execute
 * Return: lines entered
*/
void execute_cmd(char **args)
{
	pid_t child_pid = fork();

	execute_builtin(args);

	/*char *path = getenv("PATH");*/

	/*printf("PATH: %s\n", path);*/
	if (child_pid == 0)
	{
		char *command_path = resolve_command_path(args[0]);

		if (access(args[0], X_OK) == 0)
		{
			execv(command_path, args);
			perror("Bash");
			exit(1);
		}
		else
		{
			char *command_path = malloc(strlen(args[0]) + 6);

			sprintf(command_path, "/bin/%s", args[0]);
			execvp(command_path, args);
			free(command_path);
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(1);
		}
	} else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Bash");
	}
}

/**
 * kash_split_line - reads lines from std input
 * @line: command to split
 * Return: lines entered
*/
char **kash_split_line(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));
	char *delimiters = " \t\r\n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}

