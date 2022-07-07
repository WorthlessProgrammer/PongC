CC=gcc
FLAGS=-Wall -Wextra -std=c11 -pedantic -lm -lGL -lX11 -lglfw 

main:
	$(CC) $(FLAGS) main.c -o main

clear:
	rm main
