#include "main.h"
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
	char **ptr;

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
			ptr = realloc(arguments, bufsize * sizeof(char *));
			if (!ptr)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			arguments = ptr;
		}

		arg = strtok(NULL, TOKEN_DELIMITERS);
	}
	arguments[position] = NULL;
	free(ptr);
	free(arguments);
	return (arguments);
}
