#include "main.h"

/**
 * execbuilt - execute built-in
 * @args: the array of args
 *
 * Return: return value for the built infunction pointer or 1 if it failed
 */
int execbuilt(char **args)
{
	int i;
	builtin_t builtins[] = {
		{"exit", _exit_},
		{NULL, NULL}
	};
	if (args[0] == NULL)
		return (1);
	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].func());
	}
	return (1);
}

