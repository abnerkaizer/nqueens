#!/usr/bin/zsh

CC=musl-gcc
CFLAGS= -O3 -flto -g -march=native -static -pipe
TARGET= nrainhas
all:
	$(CC) $(CFLAGS) NRainhas.c -o $(TARGET)
clean:
	rm $(TARGET)
run:
	./$(TARGET)