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

# ==============================
# Google Test Integration
# ==============================

# Google Test paths
GTEST_DIR = lib/googletest
GTEST_BUILD_DIR = $(GTEST_DIR)/build
GTEST_INCLUDE = -I$(GTEST_DIR)/googletest/include
GTEST_LIBS = $(GTEST_BUILD_DIR)/lib/libgtest.a $(GTEST_BUILD_DIR)/lib/libgtest_main.a

# Test files
TEST_SRC = test/test_gameboard.cpp
TEST_OBJ = test_gameboard.o
TEST_EXEC = run_tests

# Build Google Test if needed
$(GTEST_LIBS):
	mkdir -p $(GTEST_BUILD_DIR)
	cd $(GTEST_BUILD_DIR) && cmake .. && make

# Compile test source
test_gameboard.o: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $< -o $@

# Build test binary (reuses gameboard.o)
test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(GAMEBOARD_OBJ) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -I$(GTEST_DIR) $^ -o $@ -pthread

# Clean up
clean:
	rm -f $(EXEC) $(TEST_EXEC) *.o

clean-tests:
	rm -f $(TEST_EXEC) test_gameboard.o
	rm -rf $(GTEST_BUILD_DIR)
