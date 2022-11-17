#include "main.h"

/**
* err_str - makes an error string for when a command does not exist.
* @pn: program name
* @cn: command name
* @cc: command count
*
* Return: pointer to a string which can be freed using free();
*/
char *err_str(char *pn, char *cn, char *cc, char *text)
{
	char *err_str;
	unsigned int i, j;

	i = 0;
	err_str = malloc(sizeof(char) *
			(len(pn) + len(cn) + len(cc) + len(text) + 7));
	while ((err_str[i] = pn[i]))
		++i;
	err_str[i++] = ':';
	err_str[i++] = ' ';
	j = 0;
	while ((err_str[i] = cc[j]))
		++i, ++j;
	err_str[i++] = ':';
	err_str[i++] = ' ';
	j = 0;
	while ((err_str[i] = cn[j]))
		++i, ++j;
	err_str[i++] = ':';
	err_str[i++] = ' ';
	j = 0;
	while ((err_str[i] = text[j]))
		++i, ++j;
	err_str[i] = '\0';
	write(STDOUT_FILENO, err_str, len(err_str));
	return (err_str);
}
