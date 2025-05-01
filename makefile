# === Compiler settings ===
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# === Source files ===
MAIN_SRC = main.cpp
TEST_SRC = test.cpp
MAT_SRC = SquareMat.cpp
TARGET_MAIN = main
TARGET_TEST = test

# === Default target ===
all: test

# === Compile and run test.cpp ===
test: $(TEST_SRC) $(MAT_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(MAT_SRC) -o $(TARGET_TEST)
	./$(TARGET_TEST)

# === Compile and run main.cpp ===
Main: $(MAIN_SRC) $(MAT_SRC)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) $(MAT_SRC) -o $(TARGET_MAIN)
	./$(TARGET_MAIN)

# === Check for memory leaks using valgrind (on test) ===
valgrind:
	valgrind --leak-check=full ./$(TARGET_TEST)

# === Clean up binaries ===
clean:
	rm -f $(TARGET_MAIN) $(TARGET_TEST)
