#include "shell.h"

static char *last_input;

/**
 * read_cmd - Read the line of input from user.
 *
 * Return: Pointer to a buffer conatining the user's input.
*/
char *read_cmd(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

		/* print shell prompt */
		prompt();

		/* get a line of input from user */
		nread = getline(&input, &input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(input);
			return (NULL);
		}

		/* remove trailing newline character */
		input[nread - 1] = '\0';

	/* update last_input to point to the new input */
	last_input = input;
	return (input);
}

/**
 * free_last_input - Frees the most recent input entered by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}


/**
 * tokenize - parsing user input into arguments
 *            by splits an array string into tokens using a delimiter.
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 *
 * Return: an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **ret = NULL;
	int i = 0;

	token = strtok(str, delim);
	while (token)
	{
		ret = realloc(ret, sizeof(char *) * (i + 1));
		if (ret == NULL)
			return (NULL);

		ret[i] = malloc(strlen(token) + 1);
		if (!(ret[i]))
			return (NULL);

		strcpy(ret[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	ret = realloc(ret, (i + 1) * sizeof(char *));
	if (!ret)
		return (NULL);

	ret[i] = NULL;
	return (ret);
}

/**
 * split_cmd - splits a user input string into tokens with tokenize().
 * @cmd: the user input string to be tokenized
 *
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **split_cmd(char *cmd)
{
	char **tokens = NULL;
	char *tmp = NULL;


	tmp = strdup(cmd);
	if (tmp == NULL)
	{
		puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	tokens = tokenize(tmp, " \t\r\n\a");
	free(tmp);

	return (tokens);
}


/**
 * get_line - Read input from the standard input.
 *
 * Return: The string enter by the user.
*/
void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos, buf_size;
	char *input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_size == 0)
				return (input_str);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_pos];

		buf_pos++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}
