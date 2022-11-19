#include "main.h"

void unify_delim(char *s, const char *delim);


/**
* _strtok - split a string into tokens
* @s: string;
* @delim: delimeters
*
* Description: split a string into tokens based on given delimeters
* On subsequent calls to _strtok, NULL is passed
* Return: string tokens
*/
char *_strtok(char *s, const char *delim)
{
	static char *cpy;
	static char *token;
	unsigned int i;

	if (s == NULL)
	{
		i = 0;
		if (*(cpy + i) == '\0')
			return (NULL);
		while (*(cpy + i) == ' ')
			++i;
		token = cpy + i;
		if (*token == '\0')
			return (NULL);
		while (*(cpy + i) != ' ' && *(cpy + i) != '\0')
			++i;
		if (*(cpy + i) == '\0')
			cpy = cpy + i;
		else
			*(cpy + i) = '\0';
		cpy = cpy + ++i;
	}
	else
	{
		unify_delim(s, delim);
		cpy = s;
		i = 0;
		while (*(cpy + i) && (*(cpy + i) == ' '
					|| *(cpy + i) == '\t' || *(cpy + i) == '\n'))
			++i;
		token = cpy + i;
		if (*token == '\0')
			return (NULL);
		while (*(cpy + i) != ' ' && *(cpy + i) != '\0')
			++i;
		if (*(cpy + i) == '\0')
			cpy = cpy + i;
		else
			*(cpy + i) = '\0';
		cpy = cpy + ++i;
	}
	return (token);
}

/**
* unify_delim - unifies the delimiters in a string
* @s: the string
* @delim: the delimeters
*/
void unify_delim(char *s, const char *delim)
{
	unsigned int i, j;

	i = 0;
	while (*(delim + i))
	{
		j = 0;
		while (*(s + j))
		{
			if (*(s + j) == *(delim + i))
				*(s + j) = ' ';
			++j;
		}
		++i;
	}

}
