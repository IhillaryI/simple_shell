#include "main.h"
#define voided(x) ((void) (x))

unsigned int token_count(char *s);

/**
* main - a simple shell program
* @ac: integer argument
* @argv: array of strings
*
* Description: This program really doesn't need the arguments to main.
* it only requires the argv[0] string in order to get the name of the file
*
* Return: 0 (Success)
*/
int main(int ac, char *argv[])
{
	char *lineptr;
	size_t n;
	int n_read, status;
	unsigned int tc;
	char **buf;
	size_t buf_size;
	pid_t child;
	unsigned int command_count;
	int command_stat;

	voided(ac);
	lineptr = NULL;
	n = 0;
	command_count = 0;

	do {
		if (lineptr != NULL)
		{
			++command_count;
			tc = token_count(lineptr);
			buf_size = tc + 1;
			buf = malloc(sizeof(char *) * buf_size);

			fill_buf(buf, lineptr);

			if (buf[0] == NULL)
			{
				printf("%s ", "($)");
				continue;
			}

			command_stat = com_exists(buf);
			if (command_stat == 0)
			{
				printf("%s: %u: %s: not found\n", argv[0], command_count, buf[0]);
				if (isatty(STDIN_FILENO))
					printf("%s ", "($)");
				continue;
			}
			child = fork();
			if (child == -1)
				continue;
			if (child == 0)
			{
				execve(buf[0], buf, environ);
				sleep(2);
			}
			else
			{
				wait(&status);
				if (command_stat == 2)
					free(buf[0]);
				free(buf);
			}
		}

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);


	} while ((n_read = getline(&lineptr, &n, stdin)) != -1 && (n_read != EOF));
	free(lineptr);
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
