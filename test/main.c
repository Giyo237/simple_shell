#include "shell.h"
/**
  * main - main function
  * Return: 0
  */
int main(void)
{
	size_t buf = 0;
	char **args;
	char *command = NULL;

	while (1)
	{
	write(STDOUT_FILENO, "$: ", 2);
	if (getline(&command, &buf, stdin) == -1)
	{
		perror("getline error");
		exit(EXIT_FAILURE);
	}
	command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
		break;

	}

	args = parse(command);
	executeCommand(args);

	free(args);
	}
	return (0);
}
