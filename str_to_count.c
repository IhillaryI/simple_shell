#include "main.h"

/**
* s2c - converts a string to integers
* @s: the string to convert
* Return: converted value, or 0 (error)
* return NULL
*/
int s2c(char *s)
{
	int num, i;

	num = 0;
	if (s == NULL)
		return (num);
	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\t' || *(s + i) == '\n')
		i++;
	while ((*s + i) && ((*(s + i) >= '0') && (*(s + i) <= '9')))
	{
		num = (num * 10) + (*(s + i) - '0');
		++i;
	}
	return (num);
}
