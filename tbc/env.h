
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>




extern char **environ;

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;
int _unsetenv(const char *n);
char *funcreturn(const char *name);
char *_getenv(const char *name);
char *_printpath();
list_t *add_node_end(list_t **head, const char *str);

#endif
