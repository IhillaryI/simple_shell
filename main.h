#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/**
* enum token_stat - status of a token
* @IN: first member
* @OUT: second member
*
* Description: used to check if we are currently in a token
* or on a whitespace character
*/
enum token_stat
{
	IN,
	OUT
};

void fill_buf(char **, char *);
int com_exists(char **buf);
unsigned int len(char *);
char *get_path(void);
#endif
