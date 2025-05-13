# Detect platform
OS := $(shell uname -s)

# Compiler selection
ifeq ($(OS),Darwin)
    CXX := clang++
else
    CXX := g++
endif

# Compiler flags
CXXFLAGS = -std=c++23 -Wall -Iinclude

# Main program sources
MAIN_SRC = main.cpp
GAMEBOARD_SRC = src/gameboard.cpp
GAMEBOARD_OBJ = gameboard.o
EXEC = bubblepop

# Google Test config
GTEST_DIR = lib/googletest
GTEST_BUILD = $(GTEST_DIR)/build
GTEST_INCLUDE = -I$(GTEST_DIR)/googletest/include
GTEST_LIBS = $(GTEST_BUILD)/lib/libgtest.a $(GTEST_BUILD)/lib/libgtest_main.a

# Test sources
TEST_SRCS := $(wildcard tests/*.cpp)
TEST_OBJS := $(TEST_SRCS:.cpp=.o)
TEST_BIN = test

# ==============================
# Build Targets
# ==============================

# Default build
all: $(EXEC)

# Build main program
$(EXEC): $(GAMEBOARD_OBJ) $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) $(GAMEBOARD_OBJ) -o $(EXEC)

# Compile GameBoard
$(GAMEBOARD_OBJ): $(GAMEBOARD_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==============================
# Test Build and Run
# ==============================

# Run tests (build GTest if needed)
test: $(TEST_BIN)
	./$(TEST_BIN)

# Build test binary
$(TEST_BIN): $(TEST_OBJS) $(OBJ_FILES) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) $^ -o $@ -pthread

# Compile test source
$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $< -o $@

# Build GoogleTest libs
$(GTEST_LIBS):
	mkdir -p $(GTEST_BUILD)
	cd $(GTEST_BUILD) && cmake .. && make

# ==============================
# Clean Targets
# ==============================

clean:
	rm -f $(EXEC) $(TEST_BIN) *.o

clean-all:
	rm -f $(EXEC) $(TEST_BIN) *.o
	rm -rf $(GTEST_BUILD)
