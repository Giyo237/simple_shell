#include "shell.h"
/**
 * execommand - function that executes inputed commands
 * @arg: command by user
 *Return: stat
 */
int execommand(char *arg)
{
	pid_t pid;
	int stat;
	char *args[] = {NULL};
	char *env[] = {NULL};

	pid = fork();

	if (pid == -1)
	{
		perror("failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = arg;
		/* Child process*/
		if (execve(args[0], args, env) == -1)
		{
			perror("invalid command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process*/
		waitpid(pid, &stat, 0);
		return (stat);
	}
	return (stat);
}


