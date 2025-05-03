# Detect platform
UNAME_S := $(shell uname -s)

# Choose the compiler
ifeq ($(UNAME_S),Darwin)  # macOS
    CXX := clang++
else                       # Linux, etc.
    CXX := g++
endif

# Compiler flags
CXXFLAGS = -std=c++23 -Wall -Iinclude

# Source and object files
MAIN = main.cpp
GAMEBOARD_SRC = src/gameboard.cpp
GAMEBOARD_OBJ = gameboard.o

# Executable name
EXEC = bubblepop

run: $(EXEC)
	./$(EXEC)

# Default target
all: $(EXEC)

# Link main with GameBoard.o
$(EXEC): $(GAMEBOARD_OBJ) $(MAIN)
	$(CXX) $(CXXFLAGS) $(MAIN) $(GAMEBOARD_OBJ) -o $(EXEC)

# Compile GameBoard separately
gameboard.o: $(GAMEBOARD_SRC)
	$(CXX) $(CXXFLAGS) -c $(GAMEBOARD_SRC) -o $(GAMEBOARD_OBJ)

# Clean up
clean:
	rm -f $(EXEC) *.o
