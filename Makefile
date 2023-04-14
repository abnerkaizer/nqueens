#!/usr/bin/zsh

CC=gcc
CFLAGS= -O3 -flto -g -march=native -static -pipe
TARGET= nqueens
all:
	$(CC) $(CFLAGS) nqueens.c -o $(TARGET)
clean:
	rm $(TARGET)
run:
	./$(TARGET)