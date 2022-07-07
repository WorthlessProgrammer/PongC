NAME=main
CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
LINK=-lm -lGL -lX11 -lglfw 

$(NAME):
	$(CC) $(FLAGS) $(LINK) main.c -o main
clear:
	rm main
