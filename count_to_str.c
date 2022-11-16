#include "main.h"

/**
* c2s - conversts a given number to a string.
* @count: number to convert
* Return: a pointer to a string which can be freed with free()
*/
char *c2s(unsigned int count)
{
	unsigned int num, i, j;
	char *str;

	num = count;
	i = 0;
	while (num)
	{
		++i;
		num = num / 10;
	}
	str = malloc(sizeof(char) * (i + 1));
	num = count;
	j = i;
	while (num)
	{
		str[--i] = ('0' + (num % 10));
		num = num / 10;
	}
	str[j] = '\0';
	return (str);
}
