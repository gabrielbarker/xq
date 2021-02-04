#pragma once

#include "parser/lex.yy.h"
#include "XML.hpp"
#include <unistd.h>
#include <iostream>

class Parser {
public:
    explicit Parser(const reflex::Input in);
    ~Parser();
    XML::Tag* parse();
private:
    yy::Lexer lexer;
    yy::parser *parser;
    XML::Tag *root;
};