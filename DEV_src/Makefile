NAME=test
CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
LINK=-lGL -lglut

$(NAME):
	$(CC) $(FLAGS) $(LINK) test.c -o test
clear:
	rm test
re: clear $(NAME)
