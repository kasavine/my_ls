#include "my_ls.h"

t_opt* init_opt()
{
	t_opt* opt = (t_opt*)malloc(sizeof(t_opt));
	opt->a = 0;
	opt->t = 0;
	return opt;
}

int is_opt(char *str)
{
	if (str[0] == '-')
	{
		return 1;
	}
	return 0;
}

void set_opt(t_opt* opt, char *str)
{
	int index = 0;
	while (str[index])
	{
		if (str[index] == 'a')
		{
			opt->a = 1;
		}
		if (str[index] == 't')
		{
			opt->t = 1;
		}
		index++;
	}
}

t_opt* get_opt(int ac, char **av)
{
	t_opt* opt = init_opt();
	int index = 0;

	while (index < ac)
	{
		if (is_opt(av[index]) == 1)
		{
			set_opt(opt, av[index] + 1);
		}
		index++;
	}
	return opt;
}