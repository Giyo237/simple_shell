#include "main.h"
/**
  * tokenize - function that tkenizes the input
  * @comm: command
  * @argv: argument vector
  * @numtoken: integer value for token
  */
void tokenize(char *comm, char **argv, int *numtoken)
{
	const char *delim = " \n";
	char *tok;

	tok = strtok(comm, delim);
	*numtoken = 0;
	while (tok != NULL)
	{
		argv[*numtoken] = malloc(sizeof(char) * (strlen(tok) + 1));
		if (argv[*numtoken] == NULL)
	{
		perror("hsh:memory allocation failed");
		exit(98);
	}
		strcpy(argv[*numtoken], tok);
		(*numtoken)++;
		tok = strtok(NULL, delim);;
	}
	argv[*numtoken] = NULL;
}
