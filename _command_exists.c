#include "main.h"

/**
* com_exists - checks if a command exists
* @s: the command
* 
* Return: 1 (Success), 0 (otherwise)
*/
int com_exists(char *s)
{
	if (access(s, X_OK) == 0)
		return (1);
	return (0);
}
