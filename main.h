#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "shell.h"

#define MAX_CMD_LEN 1000
#define MAX_ARGS 1024
#define BUFFER_SIZE 1024

extern char **environ;

char *prompt();

int ss_exit(char **args);
int ss_cd(char **args);
int ss_help(char **args);
int ss_env(char **args);

struct builtin{
    char *name;
    int (*builtin_func_t)(char **args);
};

extern struct builtin builtins[];

char** kash_split_line(char *line);
void execute_cmd(char **args);



#endif