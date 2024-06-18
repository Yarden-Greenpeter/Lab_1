# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Executable Name
TARGET = menu_map

# Source Files
SRCS = menu_map.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Default Rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
