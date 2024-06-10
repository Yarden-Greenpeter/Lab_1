# Makefile for count-words

CC = gcc
CFLAGS = -g -Wall
TARGET = count-words
SRC = count-words.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o
