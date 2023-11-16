#include "shell.h"
/**
  * executeCommand - handles the execution of the arg
  *@args: arguments
  * Return: stauts
  */
int executeCommand(char **args)
{
	char *com = NULL;
	pid_t pid = 0;
	int status = 0;


	if (args)
	{

		com = args[0];
		pid = fork();
		if (pid < 0)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(com, args, NULL) == -1)
			{
				perror("failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
/*	free(args);*/
	return (status);
}
