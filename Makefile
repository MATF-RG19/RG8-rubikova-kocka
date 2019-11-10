PROGRAM = rubik
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lglut -lGLU -lGL


$(PROGRAM): main.o
	$(CC) $(CFLAGS)  -o $(PROGRAM) main.o $(LDFLAGS)
