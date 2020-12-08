#include "my_ls.h"

int my_strcmp(char* s1, char* s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (isalpha(s1[i]) == 0 && isalpha(s2[i]) != 0)
        {
            return 1;
        }
        if (isalpha(s1[i]) != 0 && isalpha(s2[i]) == 0)
        {
            return -1;
        }
        if (s1[i] != s2[i])
        {
            return (s2[i] - s1[i]);
        }
        i++;
    }
    if (s2[i])
    {
        return (1);
    }
    else if (s1[i])
    {
        return (-1);
    }
    return (0);
}

int my_cmp(char* s1, char* s2)
{
    struct stat filestat_s1;
    struct stat filestat_s2;
    int i;

    stat(s1, &filestat_s1);
    stat(s2, &filestat_s2);
    if (filestat_s1.st_mtim.tv_sec > filestat_s2.st_mtim.tv_sec)
    {
        return (1);
    }
    else if (filestat_s1.st_mtim.tv_sec < filestat_s2.st_mtim.tv_sec)
    {
        return (-1);
    }
    else if (filestat_s1.st_mtim.tv_nsec > filestat_s2.st_mtim.tv_nsec)
    {
        return (1);
    }
    else if (filestat_s1.st_mtim.tv_nsec < filestat_s2.st_mtim.tv_nsec)
    {
        return (-1);
    }
    else
        return (my_strcmp(s1, s2));
    return (0);
}

int my_dircmp(char* s1, char* s2)
{
    struct stat filestat_s1;
    struct stat filestat_s2;

    stat(s1, &filestat_s1);
    stat(s2, &filestat_s2);

    if ((S_ISDIR(filestat_s1.st_mode)) && !(S_ISDIR(filestat_s2.st_mode)))
    {
        return (1);
    }
    else if (!(S_ISDIR(filestat_s1.st_mode)) && (S_ISDIR(filestat_s2.st_mode)))
    {
        return (-1);
    }
    else
        return (my_strcmp(s1, s2));
    return (0);
}

void my_sort(char** file_names, int size)
{
    int i;
    int j;
    int res;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            res = my_cmp(file_names[i], file_names[j]);
            if (res < 0)
            {
                char* tmp = file_names[i];
                file_names[i] = file_names[j];
                file_names[j] = tmp;
            }
        }
    }
}

void my_dir_sort(char** file_names, int size)
{
    int i;
    int j;
    int res;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            res = my_strcmp(file_names[i], file_names[j]);
            if (res < 0)
            {
                char* tmp = file_names[i];
                file_names[i] = file_names[j];
                file_names[j] = tmp;
            }
        }
    }
}