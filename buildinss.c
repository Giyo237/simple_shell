#include "shell.h"

/**
  *handle_command - function that handles the cmmands inputed
  * @arg: commands inputed by the user
  *Return: -1 for failure of exe(arg)
  */
int handle_command(char *arg)
{
	char cwd[BUFFER_SIZE];

	if (strcmp(arg, "exit") == 0)
	{
		write(STDOUT_FILENO, "good bye", 10);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(arg, "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(STDOUT_FILENO, "Current directory: ", 20);
			write(STDOUT_FILENO, cwd, strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			perror("getcwd");
		}
		return (1);
	}
	else if (strcmp(arg, "help") == 0)
	{
		write(STDOUT_FILENO, "This is a simple UNIX shell.\n", 48);
		write(STDOUT_FILENO, "Supported commands: 1.pwd 2.exit\n", 36);
		return (1);
	}
	else
	{
		return (execommand(arg));
	}
}
