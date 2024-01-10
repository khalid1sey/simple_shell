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

/*input_handling.c*/
char *prompt();

/*tokenize.c*/
void tokenize_cmd(char *cmd, char *args[]);

/*execute.c*/
void execute_cmd(char *args[], char *envp[]);
char *search_command(char *command, char *envp[]);
void execute_builtins(char *args[], char *envp[]);

/*builtins.c*/
void handle_cd(char *args[]);
void handle_exit();
void handle_env(char *envp[]);


#endif