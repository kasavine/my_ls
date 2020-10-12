#include "my_ls.h"

void print_opt(t_opt* opt)
{
	if (opt->a == 1)
	{
		printf("option a\n");
	}
	if (opt->t == 1)
	{
		printf("option t\n");
	}
}