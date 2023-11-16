#include "shell.h"
/**
  *parse - function that validates the arg
  *@command: command by user
  *Return:argument
  */
char **parse(char *command)
{
	int bufsize = BUFFER_SIZE;
	int position = 0;
	char **arguments = malloc(bufsize * sizeof(char *));
	char *arg;

	if (!arguments)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	arg = strtok(command, TOKEN_DELIMITERS);
	while (arg != NULL)
	{
		arguments[position] = arg;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			arguments = realloc(arguments, bufsize * sizeof(char *));
			if (!arguments)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		arg = strtok(NULL, TOKEN_DELIMITERS);
	}
	arguments[position] = NULL;
	return (arguments);
}
