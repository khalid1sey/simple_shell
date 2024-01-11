#ifndef __SHELL__H__
#define __SHELL__H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

extern char **environ;

void prompt(void);
void free_array(char **ptr);

/* input_handling.c */
char *read_cmd(void);
void free_last_input(void);
char **tokenize(char *str, const char *delim);
char **split_cmd(char *cmd);
void *get_line(void);


/* execute.c */
int execute(char **args);

/*builtins.c*/
int search_cmd(char **args);
void ss_exit(char **args);
void ss_cd(char **args);
int ss_env(void);

/* path_handling.c */
char *search_path(char *command);
char *get_path(void);

#endif
