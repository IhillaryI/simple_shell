#include "main.h"

/**
* _extstat - exits the program with an exit status
* @buf: the command buffer
* @pn: program name
* @status: the wait status
* @lineptr: the pointer to the command line
*/
void _extstat(char **buf, char *pn, char *lineptr, int status)
{
	char *err;
	int extstat;

	if (buf[1] == NULL)
	{
		free(buf);
		free(lineptr);
		exit(status);
	}
	if (buf[1][0] >= '0' && buf[1][0] <= '9')
	{
		extstat = s2c(buf[1]);
		free(buf);
		free(lineptr);
		exit(extstat);
	}
	else if (WIFEXITED(status))
	{
		free(buf);
		free(lineptr);
		exit(WEXITSTATUS(status));
	}
	else if (status == 127)
	{
		free(buf);
		free(lineptr);
		exit(127);
	}
	else
	{
		err = err_str(pn, buf[0], buf[1], "illegal number\n");
		free(err);
	}
}
