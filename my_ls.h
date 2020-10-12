#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_opt
{
	int a;
	int t;
} t_opt;

t_opt* get_opt(int ac, char **av);
void print_opt(t_opt* opt);

int my_strcmp(char *s1, char *s2);
char* my_strcpy(char *s1, char *s2);
