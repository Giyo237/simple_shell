#include "shell.h"
/**
  * main - main function
  * Return: 0
  */
int main(void)
{
	char *arg;

while (1)
	{
	 write(STDOUT_FILENO, "$: ", 2);
		arg = getcommand(arg);

		if (arg == NULL)
		{
			break;
		}
		execommand(arg);
		free(arg);
	}
	return (0);
}
