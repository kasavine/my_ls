CC		= gcc 
FLAGS	= -Wall -Wextra -Werror
NAME	= -o my_ls

my_ls: my_ls.c
	$(CC) my_ls.c $(NAME)

clean:
	rm -f my_ls

all: my_ls

push:
	git add my_ls.c Makefile
	git commit -m"auto commit"
	git push  

.PHONY: all my_ls clean
