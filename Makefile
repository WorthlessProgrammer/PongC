NAME=main
CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
LINK=-lGL -lglut -lm

$(NAME):
	$(CC) $(FLAGS) $(LINK) main.c -o main
clear:
	rm main
re: clear $(NAME)
