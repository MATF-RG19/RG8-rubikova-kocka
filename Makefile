PROGRAM = rubik
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
LDFLAGS = -lglut -lGLU -lGL -lm


$(PROGRAM): main.o mini_cube.o cube.o image.o title.o
	$(CC) $(CFLAGS)  -o $(PROGRAM) main.o mini_cube.o cube.o image.o title.o $(LDFLAGS)

main: main.o lib.h colors.h
	$(CC) $(CFLAGS)  -o $(PROGRAM) main.o $(LDFLAGS)
cube: cube.c lib.h colors.h
	$(CC) $(CFLAGS)  -o cube.c cube.o $(LDFLAGS)
mini_cube: mini_cube.o lib.h colors.h
	$(CC) $(CFLAGS)  -o mini_cube.c mini_cube.o $(LDFLAGS)
title: title.c lib.h image.h image.o
	$(CC) $(CFLAGS)  -o image.c image.o title.c title.o $(LDFLAGS)
.PHONY:
	clean
clean: 
	rm -fv *.o
