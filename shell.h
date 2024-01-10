#ifndef __SHELL__H__
#define __SHELL__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CMD_LEN 1000
#define MAX_ARGS 1024
#define BUFFER_SIZE 1024

extern char **environ;

int ss_exit(char **args);
int ss_env(char **args);


/**
 * struct builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @name: - Built-in command
 * @builtin_func_t: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct
{
	char *name;
	int (*builtin_func_t)(char **args);
} builtin_t;

extern builtin_t builtins[];

char *prompt();
char** kash_split_line(char *line);
void execute_cmd(char **args);
void execute_builtin(char **args);
char *resolve_command_path(char *command);


#endif