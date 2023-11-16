#include "shell.h"
/**
  * executeCommand - handles the execution of the arg
  *@args: arguments
  * Return: stauts
  */
int executeCommand(char **args)
{
	char *com = NULL;

	if (args)
	{
		com = args[0];
		if (execve(com, args, NULL) == -1)
		{
			perror("ERROR");
		};
	}
	return (0);
}
