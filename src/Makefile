REFLEX_VERSION=3.0.1

INCDIR = ../include

REFLEX_INCPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/include
REFLEX_LIBPATH = /usr/local/Cellar/re-flex/$(REFLEX_VERSION)/lib
REFLEX_LIB = reflex

BUILDDIR = ../build

PARSER_SRCS=./parser/xml.yy.cpp ../include/parser/xml.tab.cxx
SRCS=$(shell find . -name '*.cpp' | grep -v ./parser/xml.yy.cpp)

CXXFLAGS = -Wall -I$(INCDIR)
CXX = g++

defintion:
	make -C parser
	$(CXX) $(CXXFLAGS) -I$(REFLEX_INCPATH) -o $(BUILDDIR)/xml $(SRCS) $(PARSER_SRCS) -L$(REFLEX_LIBPATH) -l$(REFLEX_LIB)
clean:
	make clean -C parser
