    #include <stdio.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <sys/stat.h>

    typedef struct t_opt
    {
        int a;
        int t;
    } t_opt;

    void my_memset(char* buff, char c, int size);
    void my_bzero(char* buff, int size);
    char* my_init(int size);
    
    int is_opt(char* str);
    void set_opt(t_opt* opt, char* str);
    t_opt* get_opt(int ac, char** av);

    int my_strcmp(char* s1, char* s2);
    int my_cmp(char* s1, char* s2);
    int my_dircmp(char* s1, char* s2);
    void my_sort(char** file_names, int size);
    void my_dir_sort(char** file_names, int size);

    int my_read_dir();
