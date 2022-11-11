#include "main.h"

/**
* get_path - returns PATH string
*
* Description: this function returns the path string
* the pointer returned, can be freed using free()
* Return: a string, otherwise NULL
*/
char *get_path(void)
{
	char *query, *path;
	unsigned int i, j, index;

	i = 0;
	query = "PATH";
	while (environ[i] != NULL)
	{
		j = 0;
		while (*(environ[i] + j) == query[j] && query[j] != '\0')
			++j;
		if (query[j] == '\0')
			index = i;
		++i;
	}

	path = malloc(sizeof(char) * (len(environ[index]) - 4));
	i = 0;
	while (*(environ[index] + i) == query[i] && query[i] != '\0')
		++i;
	++i;
	j = 0;
	while ((path[j] = environ[index][i]))
		++i, ++j;
	return (path);
}
