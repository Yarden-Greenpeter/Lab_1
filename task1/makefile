# Makefile for task1

CC = gcc
CFLAGS = -g -Wall
TARGET = addresses
SRC = addresses.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o
