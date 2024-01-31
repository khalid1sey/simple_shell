#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	
	hsh(info, av);
	
	return (EXIT_SUCCESS);
}

struct termios orig_termios; // original terminal settings

void enableRawMode()
{
    struct termios raw;

    // Get the original terminal attributes
    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;

    // Disable canonical mode (line buffering) and echo
    raw.c_lflag &= ~(ECHO | ICANON);

    // Set the modified terminal attributes
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableRawMode()
{
    // Restore the original terminal attributes
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

char readKey()
{
    char c;
	read(STDIN_FILENO, &c, 1);
    return c;
}

void processKey(char c)
{
    switch (c) {
        case '\x1b': // Escape key
            // Handle escape sequences for arrow keys
            {
                char seq[3];
                if (read(STDIN_FILENO, &seq[0], 1) != 1 || read(STDIN_FILENO, &seq[1], 1) != 1) {
                    // Error or incomplete escape sequence
                    return;
                }

                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'A': // Up arrow
                            // Handle up arrow logic
                            printf("Up arrow pressed.\n");
                            break;
                        case 'B': // Down arrow
                            // Handle down arrow logic
                            printf("Down arrow pressed.\n");
                            break;
                        case 'C': // Right arrow
                            // Handle right arrow logic
                            printf("Right arrow pressed.\n");
                            break;
                        case 'D': // Left arrow
                            // Handle left arrow logic
                            printf("Left arrow pressed.\n");
                            break;
                    }
                }
            }
            break;
        default:
            // Handle other key presses
            printf("Key pressed: %c\n", c);
            break;
    }
}
