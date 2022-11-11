#include "main.h"

/**
* len - count characters in a string
* @s: the string
* Return: the length of characters in a string
*/
unsigned int len(char *s)
{
	unsigned int i;

	i = 0;
	while (*(s + i))
		++i;
	return (i);
}
