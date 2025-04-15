# Compiler and flags:
CXX      = g++
CXXFLAGS = -std=c++11 -O2 -Wall

# Name of the final executable:
TARGET = benchmark

# Source files (adjust the names if needed)
SRCS = main.cpp QuickUnion.cpp

# Object files (derived from sources):
OBJS = $(SRCS:.cpp=.o)

# Default target builds the executable:
all: $(TARGET)

# Link object files to create the executable.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Generic rule for compiling C++ sources.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files.
clean:
	rm -f $(TARGET) $(OBJS)

# Run the benchmark executable.
run: $(TARGET)
	./$(TARGET)
