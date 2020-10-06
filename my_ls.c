#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    if (s2[i] != '\0')
    {
        return (s1[i] - s2[i]);
    }
    return 0;
}

char *my_strcpy(char *s1, char *s2);

int main ()
{
    DIR *folder;
    struct dirent *dir;
    struct stat filestat;
    char name[256][256];
    int count = 0;
    int i = 0;

    folder = opendir(".");
    if (folder == NULL)
    {
        perror("Unable to read directory");
        return (1);
    }
    while ((dir = readdir(folder)) != NULL)
    {
        stat(dir->d_name, &filestat);
        if (S_ISDIR(filestat.st_mode))
        {
            if (my_strcmp(dir->d_name, "." ) == 1 || my_strcmp(dir->d_name, ".." ) == 1)
            {
                strcpy(name[count], dir->d_name);
                count++;
            }
        }
        else
        {
            strcpy(name[count], dir->d_name);
            count++;
        }
    }
    // The stat and readlink utilities exit 0 on success, and >0 if an error occurs.
    while(count > 0)
    {
        printf("%s\n", name[i]);
        i++;
        count--;
    }
    closedir(folder);
    return (0);
}