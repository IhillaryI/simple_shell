#include "main.h"

int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * _getline - getline
 * @lineptr: pointer to the memory to save the string
 * @n: pointer to the number of string to get
 * @fd: to read from
 *
 * Return: the bytes of string
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char buffer[120];

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = sizeof(buffer);
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (read(fd, buffer, sizeof(buffer)) > 0)
	{
		if (*n - _strlen(*lineptr) < sizeof(buffer))
		{
			*n += sizeof(buffer);
			*lineptr = _realloc(*lineptr, *n - sizeof(buffer), *n);
			if (*lineptr == NULL)
			{
				free(lineptr);
				return (-1);
			}
		}
		_strcat(*lineptr, buffer);
		if (_strchr(*lineptr, '\n') != NULL)
			break;
	}
	return (_strlen(*lineptr));
}

/**
 * _strlen - get the length of a string
 *
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcat - join two string together
 * @dest: destination string
 * @src: source string
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}


/**
 * _strchr - find the location of a character in a string
 * @s: the string
 * @c: the character to find
 * Return: the string from the position the character was found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _realloc - realloc a malloc'ed memory
 * @ptr: the previously malloc'ed memory
 * @old_size: the size of the memory previousl allocated
 * @new_size: the size of the new memory
 *
 * Return: void pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}

