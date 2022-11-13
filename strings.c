#include "main.h"
/**
 * _strcmp - Compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if not the same and 0 othrwise
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) && *(s2 + i); i++)
	{
		if (*(s1 + i) != *(s2 + i))
			return (1);
	}
	return (0);
}
