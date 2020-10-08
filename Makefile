CC		= gcc 
FLAGS	= -g3 -fsanitize=address -Wall -Wextra -Werror
NAME	= my_ls

all: $(NAME)

$(NAME): my_ls.o
	$(CC) $(FLAGS) my_ls.o -o $(NAME)

main.o: main.c
	$(CC) $(FLAGS) -c my_ls.c

clean:
	rm *.o $(NAME)

push:
	git add my_ls.c Makefile my_ls.h
	git commit -m"auto commit"
	git push  

.PHONY: all clean
