#include <unistd.h>
#include "shell.h"
/**
 * display - function that displays a welcome mesage
 * @c: our character variable
 */
void display(char *c)
{
	write(STDOUT_FILENO, &c, 1);
}
/**
 * main - function that calls the display func
 * Return: 0
 */
int main(void)
{
	char *welcome = "welcome to our group project";

	display(welcome);
	return (0);
}
