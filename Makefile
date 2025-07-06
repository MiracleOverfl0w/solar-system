# Define compilers
CXX = g++        # C++ compiler
CC = gcc         # C compiler (for glad.c)

# Compiler flags
# -std=c++17: C++ standard
# -Iinclude: Add the 'include' directory to the compiler's search path for headers
# -Wall: Enable all standard warnings (highly recommended)
# -Wextra: Enable additional warnings
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra
CFLAGS = -Wall -Wextra -Iinclude # C flags, similar to CXXFLAGS

# Output executable name
OUT = solar_system

# Source files
# Use wildcard to automatically find .cpp and .c files
# Exclude the test directory if testfunc.cpp is not part of the main build
CPP_SRCS = $(wildcard src/*.cpp)
C_SRCS = $(wildcard src/*.c) # For glad.c

# If testfunc.cpp IS part of your main build:
# CPP_SRCS += src/test/testfunc.cpp

# If testfunc.cpp is NOT part of your main build, and just for separate testing:
# You'd create a separate target for building tests, e.g.:
# test: src/test/testfunc.cpp
#   $(CXX) $(CXXFLAGS) -o test_runner src/test/testfunc.cpp $(LIBS)

# Generate object file names from source files
# Replaces .cpp with .o and .c with .o
OBJ = $(CPP_SRCS:.cpp=.o) $(C_SRCS:.c=.o)

# Libraries
# -lglfw: GLFW library for windowing and input
# -ldl: Dynamic linking library (often needed on Linux for GLFW)
# -lGL: OpenGL library
# -lm: Math library (for functions like sin, cos, sqrt)
# Removed -static to avoid issues with GLIBC
LIBS = -lglfw -ldl -lGL -lm

# --- Main Build Rules ---

.PHONY: all clean # Phony targets don't correspond to actual files

all: $(OUT)

# Rule for linking the final executable
$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LIBS)

# Rule for compiling C++ source files into object files
# $@: target (e.g., src/main.o)
# $<: first prerequisite (e.g., src/main.cpp)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for compiling C source files into object files (specifically for glad.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OUT) $(OBJ) # Remove the executable and all object files
	# You might also want to clean up any test binaries if you add a test target