CC		= gcc 
FLAGS	= -g3 -fsanitize=address #-Wall -Wextra -Werror
NAME	= my_ls

all: $(NAME)

$(NAME): main.o get_opt.o dir.o my_sort.o
	$(CC) $(FLAGS) main.o get_opt.o dir.o my_sort.o -o $(NAME)

get_opt.o: get_opt.c
	$(CC) $(FLAGS) -c get_opt.c

dir.o: dir.c
	$(CC) $(FLAGS) -c dir.c

my_sort.o: my_sort.c
	$(CC) $(FLAGS) -c my_sort.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

clean:
	rm *.o $(NAME)
	
.PHONY: all clean
