CC=gcc
FLAGS=-Wall -Wextra -std=c11 -pedantic

main:
	$(CC) main.c $(FLAGS) -o main
