PROGRAM = rubik
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lglut -lGLU -lGL


$(PROGRAM): main.o mini_cube.o
	$(CC) $(CFLAGS)  -o $(PROGRAM) main.o mini_cube.o $(LDFLAGS)

main: main.o lib.h
	$(CC) $(CFLAGS)  -o $(PROGRAM) main.o $(LDFLAGS)
mini_cube: mini_cube.o lib.h
	$(CC) $(CFLAGS)  -o mini_cube.c mini_cube.o $(LDFLAGS)
