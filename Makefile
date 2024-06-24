# Define the compiler to use
CC = gcc

# Define compiler flags
# -Iinclude: Add 'include' directory to the list of directories to be searched for header files
# -Wall: Enable all common warnings
# -Wextra: Enable extra warnings
CFLAGS = -Iinclude -Wall -Wextra -I/usr/local/include

LDFLAGS = -L/usr/local/lib -lraylib

# Find all source files in the 'src' directory
SRC = $(wildcard src/*.c)

# Convert source file paths to object file paths in the 'build' directory
OBJ = $(SRC:src/%.c=build/%.o)

# Define the name of the final executable
TARGET = snake

# Default target to build the executable
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile each .c file into an .o object file in the 'build' directory
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -rf build/*.o $(TARGET)

# Declare 'all' and 'clean' as phony targets (they do not correspond to actual files)
.PHONY: all clean

