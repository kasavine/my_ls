CC		= gcc 
FLAGS	= -g3 -fsanitize=address #-Wall -Wextra -Werror
NAME	= my_ls

all: $(NAME)

$(NAME): main.o get_opt.o print_opt.o
	$(CC) $(FLAGS) main.o get_opt.o print_opt.o -o $(NAME)

get_opt.o: get_opt.c
	$(CC) $(FLAGS) -c get_opt.c

print_opt.o: print_opt.c
	$(CC) $(FLAGS) -c print_opt.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

clean:
	rm *.o $(NAME)

push:
	git add *.c Makefile my_ls.h
	git commit -m"auto commit"
	git push  

.PHONY: all clean
