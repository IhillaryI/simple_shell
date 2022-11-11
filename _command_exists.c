#include "main.h"

/**
* com_exists - checks if a command exists
* @buf: the command buffer
*
* Description: If return value == 2, free buf[0] with free()
*
* Return: 1 (Success_1), 2 (success_2), 0 (otherwise)
*/
int com_exists(char **buf)
{
	char *path, *f_path, *token;
	unsigned int i, j, found;

	if (access(buf[0], X_OK) == 0)
		return (1);
	found = 0;
	path = get_path();
	if (path)
	{
		token = strtok(path, ":");
		while (token != NULL)
		{
			f_path = malloc(sizeof(char) * (len(buf[0]) + len(token) + 2));
			i = 0;
			while ((f_path[i] = token[i]) && token[i] != '\0')
				++i;
			f_path[i++] = '/';
			j = 0;
			while ((f_path[i] = buf[0][j]) && buf[0][j] != '\0')
				++i, ++j;
			if (access(f_path, X_OK) == 0)
			{
				found = 1;
				buf[0] = malloc(sizeof(char) * (len(f_path) + 1));
				i = 0;
				while ((buf[0][i] = f_path[i]) && f_path[i] != '\0')
					++i;
				break;
			}
			free(f_path);
			token = strtok(NULL, ":");
		}
		free(path);
		if (found)
		{
			free(f_path);
			return (2);
		}
	}
	return (0);
}

