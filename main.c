#include "my_ls.h"

int main(int argc, char** argv)
{
    if (argc >= 1)
    {
        int i = 1;
        int counter = 0;
        t_opt* opt = get_opt(argc, argv);
        while (i < argc)
        {
            if (is_opt(argv[i]) == 0)
            {
                // printf("%s:\n", argv[i]);
                my_read_dir(opt, argv[i]);
                counter++;
            }
            i++;
        }
        if (counter == 0)
        {
            my_read_dir(opt, ".");
        }
        free(opt);
    }
}