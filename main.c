#include "main.h"
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
		perror("error");
		exit(EXIT_FAILURE);
	}
	command[strspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
		break;

	}

	args = parse(command);
	if (isvalid(args))
	{
		executeCommand(args);
	}
	else
	{
		write(STDOUT_FILENO, "invalid command: ", 17);
		write(STDOUT_FILENO, args[0], strlen(args[0]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(args);
	}

	free(command);

	return (0);
}
