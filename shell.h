#ifndef MAIN_H
#define MAIN_H
#define  BUFFER_SIZE 1024
extern char **environ;

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
/*#include <wait/sys.h>*/

/*void display(char *c);*/
char* getcommand (char *buf);
int execommand(char *arg);

#endif
