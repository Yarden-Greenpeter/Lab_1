CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = map_test

# List of object files if your program consists of multiple source files
# OBJ = base.o file1.o file2.o

all: $(TARGET)

$(TARGET): base.o
	$(CC) $(CFLAGS) $^ -o $@

base.o: base.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up intermediate object files and executable
clean:
	rm -f $(TARGET) *.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Default target
.DEFAULT_GOAL := all