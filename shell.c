#include "main.h"

unsigned int token_count(char *s);

/**
* main - a simple shell program
* Return: 0 (Success)
*/
int main(void)
{
	char *lineptr;
	size_t n;
	size_t n_read;
	unsigned int tc;
	char **buf;
	size_t buf_size;

	lineptr = NULL;
	n = 0;

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		if (lineptr != NULL)
		{
			tc = token_count(lineptr);
			buf_size = tc + 1;
			buf = malloc(sizeof(char *) * buf_size);

			fill_buf(buf, lineptr);

			free(lineptr);
			free(buf);
		}
	} while ((n_read = getline(&lineptr, &n, stdin)) != -1 && (n_read != EOF));
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}


/**
* token_count - return the number of tokens in a string
* @s: the string
* Return: number of tokens in a string
*/
unsigned int token_count(char *s)
{
	unsigned int i, count;
	unsigned int token_stat;

	if (s == NULL)
		return (0);

	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		++i;

	token_stat = IN;
	if (*(s + i) == '\0')
		return (0);
	count = 1;
	while (*(s + i))
	{
		if (*(s + i) == ' ' || *(s + i) == '\t')
			token_stat = OUT;
		else
			if (token_stat == OUT)
			{
				token_stat = IN;
				++count;
			}
		++i;
	}
	return (count);
}
