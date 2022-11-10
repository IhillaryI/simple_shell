#include "main.h"

/**
* main - a simple shell program
* Return: 0 (Success)
*/
int main(void)
{
	char *lineptr;
	size_t n;
	size_t n_read;

	lineptr = NULL;
	n = 0;

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
	} while ((n_read = getline(&lineptr, &n, stdin)) != -1 && (n_read != EOF));
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
