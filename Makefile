# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and object files
SRC = server.c http.c router.c file_server.c
OBJ = $(SRC:.c=.o)

# Output binary
TARGET = server

# Default rule
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files to .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)
