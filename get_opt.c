#include "my_ls.h"

void my_memset(char* buff, char c, int size)
{
    int index = 0;
    while (index < size)
    {
        buff[index] = c;
        index++;
    }
}

void my_bzero(char* buff, int size)
{
    my_memset(buff, 0, size);
}

char* my_init(int size)
{
    char* buff = (char*)malloc(size);
    my_bzero(buff, size);
    return buff;
}

int is_opt(char* str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    return 0;
}

void set_opt(t_opt* opt, char* str)
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

t_opt* get_opt(int ac, char** av)
{
    t_opt* opt = (t_opt*)my_init(sizeof(t_opt));
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