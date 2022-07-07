CC=gcc
FLAGS=-Wall -Wextra -std=c11 -pedantic -lm

main:
	$(CC) $(FLAGS) main.c -o main

clear:
	rm main
