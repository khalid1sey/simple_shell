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

char *prompt();
char** kash_split_line(char *line);
void execute_cmd(char **args);
char *resolve_command_path(char *command);

int ss_exit(char **args);
int ss_help(char **args);
int ss_env(char **args);


#endif