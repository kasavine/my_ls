#include "my_ls.h"

int main(int argc, char **argv)
{
	t_opt* opt = get_opt(argc, argv);
	print_opt(opt);
	free(opt);
}
