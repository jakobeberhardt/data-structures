CXX      := g++
CXXFLAGS := -std=c++20 -O3 -march=native -DNDEBUG -Iinclude -Wall -Wextra

SRC  := $(wildcard src/*.cpp)
OBJ  := $(SRC:src/%.cpp=build/%.o)
BIN  := bst-bench

TEST_SRC   := $(wildcard test/*.cpp)
TEST_OBJ   := $(TEST_SRC:test/%.cpp=build/test/%.o)
TEST_BIN   := bst-tests

TEST_CXXFLAGS := $(filter-out -DNDEBUG,$(CXXFLAGS))

.PHONY: test
test: $(TEST_BIN)
	@echo "Running unit tests…"
	@./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJ)
	$(CXX) $(TEST_CXXFLAGS) $^ -o $@

build/test/%.o: test/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf build $(BIN) bst-tests
