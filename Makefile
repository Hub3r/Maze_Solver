CXX = g++
CXXFLAGS = -g -std=c++20 -Wall -Wextra -I./maze_objects/inc -I./solving_algorithms/handOnWall

SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) \
            $(wildcard $(SRC_DIR)/maze_objects/*.cpp) \
            $(wildcard $(SRC_DIR)/solving_algorithms/breadth_first/*.cpp)
            
OBJ_DIR = ./build
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

TARGET = maze_solver

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)/maze_objects
	@mkdir -p $(OBJ_DIR)/solving_algorithms/breadth_first
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
