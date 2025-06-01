# ==============================
# Platform & Compiler Selection
# ==============================
OS := $(shell uname -s)
CXX := $(if $(filter Darwin,$(OS)),clang++,g++)

CXXFLAGS = -std=c++23 -Wall -Iinclude

# ==============================
# Directories
# ==============================

SRC_DIR := src
TEST_DIR := tests
BUILD_DIR := build

# ==============================
# Source & Object Files
# ==============================

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

MAIN_FILE := main.cpp
EXEC := bubblepop

# ==============================
# GoogleTest Configuration
# ==============================

GTEST_DIR     := lib/googletest
GTEST_BUILD   := $(GTEST_DIR)/build
GTEST_INCLUDE := -I$(GTEST_DIR)/googletest/include
GTEST_LIBS    := $(GTEST_BUILD)/lib/libgtest.a $(GTEST_BUILD)/lib/libgtest_main.a

# ==============================
# Test Sources
# ==============================

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/test_%.o,$(TEST_SRCS))
TEST_BIN := test_runner

# ==============================
# Build Targets
# ==============================

.PHONY: all build-objects build test gtest clean clean-all

# Default build
all: build

exec:
	./$(EXEC)

# Build object files from src/
build-objects: $(OBJ_FILES)

# Build main executable
build: $(OBJ_FILES) $(MAIN_FILE)
	$(CXX) $(CXXFLAGS) $(MAIN_FILE) $(OBJ_FILES) -o $(EXEC)

debug: CXXFLAGS += -g -O0
debug: BUILD_TYPE := debug
debug: $(OBJ_FILES) $(MAIN_FILE)
	$(CXX) $(CXXFLAGS) $(MAIN_FILE) $(OBJ_FILES) -o bubblepop_debug

# Compile src .cpp to build/*.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==============================
# Test Build and Run
# ==============================

test: CXXFLAGS += -g -O0
test: gtest $(TEST_BIN)
	./$(TEST_BIN)

test_build: CXXFLAGS += -g -O0
test_build: gtest $(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS) $(OBJ_FILES) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) $^ -o $@ -pthread

# Compile test .cpp to build/test_%.o
$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $< -o $@
$(TEST_BIN): $(TEST_OBJS) $(OBJ_FILES) $(GTEST_LIBS)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) $^ -o $@ -pthread

# Compile test .cpp to build/test_*.o
$(BUILD_DIR)/test_%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GTEST_INCLUDE) -c $< -o $@

# ==============================
# Build GoogleTest (if needed)
# ==============================

gtest: $(GTEST_LIBS)

$(GTEST_LIBS):
	mkdir -p $(GTEST_BUILD)
	cd $(GTEST_BUILD) && cmake .. && make

# ==============================
# Clean Targets
# ==============================

clean:
	rm -f $(EXEC) $(TEST_BIN)
	rm -rf $(BUILD_DIR)
	rm -rf bubblepop_debug

clean-all: clean
	rm -rf $(GTEST_BUILD)
