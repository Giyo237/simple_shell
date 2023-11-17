#include "main.h"
/**
  * main - main function
  * Return: 0
  */
int main (void)
{
	char *command = NULL;
	char *copy = NULL;
	size_t i = 0;
	ssize_t read;
	int numtoken = 0, j = 0;


while (1)
{
	write(STDOUT_FILENO, "$: ", 2);
	read = getline(&command, &i, stdin);
	copy = malloc(sizeof(char) * read + 1);
	if (copy == NULL)
	{
		perror("hsh: memey allocation failed");
		return (-1);
	}

	strcpy(copy, command);

	if (read == -1)
	{
		printf("exiting shell...\n");
		return (-1);
	}
	else
	{
		char **argv = malloc(sizeof(char *) * (numtoken +1));

		if (argv == NULL)
		{
			perror("hsh:memory allocation failed");
			return (-1);
		}

		tokenize(command, argv, &numtoken);
		argv[numtoken] = NULL;

		execmd(argv);

		for (j = 0; j < numtoken; j++)
		{
			free(argv[j]);
		}
		free(argv);
	}

		free(command);
		free(copy);
}

	return (0);
}
