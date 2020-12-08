#include "my_ls.h"

int my_read_dir(t_opt* opt, char* dir_path)
{
    DIR* folder;
    struct dirent* dir;
    struct stat filestat;
    char** name;
    int count = 0;
    int i = 0;

    folder = opendir(dir_path);
    if (folder == NULL)
    {
        perror("Unable to read directory");
        return (1);
    }
    name = (char**)malloc(sizeof(char*) * 256);
    while ((dir = readdir(folder)) != NULL)
    {
        stat(dir->d_name, &filestat);
        if (dir->d_name[0] == '.' && opt->a == 0)
        {
            continue;
        }
        name[count] = strdup(dir->d_name);
        count++;
    }
    if (opt->t == 1)
    {
        my_sort(name, count);
    }
    else
    {
        my_dir_sort(name, count);
    }
    while (i < count)
    {
        printf("%s\n", name[i]);
        i++;
    }
    closedir(folder);
    i = 0;
    while (i < count)
    {
        free(name[i]);
        i++;
    }
    free(name);
    return (0);
}
