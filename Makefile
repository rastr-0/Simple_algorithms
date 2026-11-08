# Build every algorithm into build/<category>/<name>
#   make            build everything
#   make test       build and run the tests
#   make clean      remove build/
# Extra checks: make clean && make test CXXFLAGS="-std=c++17 -g -fsanitize=address,undefined"

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2

SRCS := $(wildcard */*.cpp)
BINS := $(patsubst %.cpp,build/%,$(SRCS))

all: $(BINS)

build/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

test: all
	@./tests/run_tests.sh

clean:
	rm -rf build

.PHONY: all test clean
