#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\n\r\a\"\'`\\*&#"


char **parse(char *command);
int executeCommand(char **args);

#endif
