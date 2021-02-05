#include "Parser.hpp"

Parser::Parser(const reflex::Input in) : lexer(in), parser(new yy::parser(lexer, &root)) { 
    root = nullptr; 
}

Parser::~Parser() { 
    delete parser; 
}

XML::Tag* Parser::parse() {
    parser->set_debug_level(0);
    std::cout << "Running parser" << std::endl;
    int result = parser->parse();
    if (result == 0) {  // 0 == success, 1 == failure
        std::cout << "Extracting result" << std::endl;
        if (root == nullptr) {
            std::cout << "Null result" << std::endl;
        }
        root->print();
        return root;
    } else {
        std::cout << "Parse failed, no tree" << std::endl;
        return nullptr;
    }
}