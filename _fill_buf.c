#include "main.h"

/**
* fill_buf - fills a buffer with tokens
* @buf: the buffer to fill
* @s: token source
*/
void fill_buf(char **buf, char *s)
{
	char *token;
	unsigned int i;

	i = 0;
	token = _strtok(s, "\t \n");
	while (token != NULL)
	{
		buf[i] = token;
		token = _strtok(NULL, "\t \n");
		++i;
	}
	buf[i] = NULL;
}
