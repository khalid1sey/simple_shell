#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CMD_LEN 1000
#define MAX_ARGS 1024

void prompt(char *cmd);
int check_cmd_exists(char *cmd, char *path);
void executecmd(char *cmd, int comcounter);

#endif