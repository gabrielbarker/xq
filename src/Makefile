REFLEX_VERSION=3.0.1

REFLEX_INCPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/include
REFLEX_LIBPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/lib
REFLEX_LIB = reflex

BINDIR = ../bin

PARSER_SRCS=./parser/lex.yy.cpp ./parser/xml.tab.cxx
SRCS=$(shell find . -name '*.cpp')

CXXFLAGS = -Wall -Wextra -Wpedantic
CXX = g++

defintion:
	make -C parser
	$(CXX) -I$(REFLEX_INCPATH) -o $(BINDIR)/xml $(SRCS) $(PARSER_SRCS) -L$(REFLEX_LIBPATH) -l$(REFLEX_LIB)
clean:
	make clean -C parser
