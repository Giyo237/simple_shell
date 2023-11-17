#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\n\r\a\"\'`\\*&#"

void cleanit(char **arguments);
char **parse(char *command);
int executeCommand(char **args);
size_t customstrspn(const char *s, const char *accept);
int customstrcmp(const char *s1, const char *s2);

#endif
