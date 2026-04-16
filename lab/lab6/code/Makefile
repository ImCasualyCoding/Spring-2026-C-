# Variables for the compiler and flags
CXX = g++
CXXFLAGS = -g -Wall

# The name of your final program
TARGET = lab6_program

# The files to compile
SRCS = main.cpp functions.cpp

# Default rule: This runs when you just type 'make'
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Rule to clean up the folder (removes the executable)
clean:
	rm -f $(TARGET)
