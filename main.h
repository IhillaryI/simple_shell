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

/**
 * struct builtin - struct builtin
 * @name: name of the builtin
 * @func: function pointer to the respective function
 */
typedef struct builtin
{
	char *name;
	int (*func)(void);
} builtin_t;

void fill_buf(char **, char *);
int com_exists(char **buf);
int _exit_(void);
unsigned int len(char *);
char *get_path(void);
void handle_err(char *pn, char *cn, unsigned int cc);
int _strcmp(char *, char *);
int execbuilt(char **);
char *c2s(unsigned int);
char *err_str(char *, char *, char *);
int s2c(char *s);
char *_strtok(char *s, const char *delim);
#endif
