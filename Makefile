REFLEX_VERSION=3.0.1
TEST_VERSION=2.0.0

REFLEX_INCPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/include
REFLEX_LIBPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/lib
REFLEX_LIB = reflex

TEST_INCPATH = /usr/local/Cellar/unittest-cpp/$(TEST_VERSION)/include/UnitTest++/
TEST_LIBPATH = /usr/local/Cellar/unittest-cpp/$(TEST_VERSION)/lib/
TEST_LIB = UnitTest++

MAIN=src/main.cpp
PARSER_SRCS=./src/parser/lex.yy.cpp ./src/parser/xml.tab.cxx
SRCS = $(shell find src -name '*.cpp' -depth 1 | grep -v $(MAIN))
TESTS = $(shell find tests -name '*.cpp')

# CXXFLAGS = -Wall -Wextra -Wpedantic -I$(INCDIR)
TEST_LIB_FLAGS = -L$(TEST_LIBPATH) -I$(TEST_INCPATH) -l$(TEST_LIB)
REFLEX_LIB_FLAGS = -L$(REFLEX_LIBPATH) -I$(REFLEX_INCPATH) -l$(REFLEX_LIB)

CXX = g++

defintion:
	make -C src
test: $(TESTS)
	make -C src/parser
	$(CXX) $(REFLEX_LIB_FLAGS) $(TEST_LIB_FLAGS) $(PARSER_SRCS) $(SRCS) $(TESTS) -o bin/$@
clean:
	make clean -C src
	rm -r bin/
	mkdir bin