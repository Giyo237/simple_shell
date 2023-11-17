#include "main.h"
/**
  * cleanit - functin that chexks for leaks
  * @arguments: args
  */
void cleanit(char **arguments)
{
	int i;

	if (arguments != NULL)
	{
	for (i = 0; arguments[i] != NULL; i++)
	{
		free(arguments[i]);
	}
	/*free(arguments);*/
	}
}

