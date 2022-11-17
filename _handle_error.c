#include "main.h"

/**
* handle_err - prints an error message to stdout
* @pn: program name
* @cn: command name
* @cc: command counts
*/
void handle_err(char *pn, char *cn, unsigned int cc)
{
	char *str;
	char *err_;

	str = c2s(cc);
	err_ = err_str(pn, cn, str, "not found\n");
	free(err_);
	free(str);
}
