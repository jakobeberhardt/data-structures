CXX      := g++
CXXFLAGS := -std=c++20 -O3 -march=native -DNDEBUG -Iinclude -Wall -Wextra

SRC  := $(wildcard src/*.cpp)
OBJ  := $(SRC:src/%.cpp=build/%.o)
BIN  := bst-bench

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build $(BIN)
