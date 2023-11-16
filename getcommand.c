#include "shell.h"
/**
* getcommand - function that reads the users command
* Return: buf
*@buf: store for the commands inputed
*/
char *getcommand(char *buf)
{
	size_t bufsize = 0;
	ssize_t char_read;

	buf = NULL;
	char_read = getline(&buf, &bufsize, stdin);

	if (char_read == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[char_read - 1] = '\0';
	return (buf);
}
