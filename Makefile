CC=gcc
FLAGS=-Wall -Wextra -std=c11 -pedantic

main:
	$(CC) $(FLAGS) main.c -o main
