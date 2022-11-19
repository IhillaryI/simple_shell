#include "main.h"

/**
* _extstat - exits the program with an exit status
* @buf: the command buffer
* @pn: program name
* @status: the wait status
* @exit_status: the exit status
* @lineptr: the pointer to the command line
*/
void _extstat(char **buf, char *pn, char *lineptr, int status, int exit_status)
{
	char *err;
	int extstat;

	if (status == 127)
	{
		free(buf);
		free(lineptr);
		exit(127);
	}
	if (buf[1])
	{
		free(buf);
		free(lineptr);
		extstat = s2c(buf[1]);
		if (buf[1][0] >= '0' && buf[1][0] <= '9')
			exit(extstat);

		err = err_str(pn, buf[0], buf[1], "illegal number\n");
		free(err);
	}
	else
		exit(0);
	if (exit_status == 0)
	{
		free(buf);
		free(lineptr);
		exit(status);
	}
}
