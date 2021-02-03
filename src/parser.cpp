#include "parser/lex.yy.h"
#include "xml.hpp"
#include <unistd.h>
#include <iostream>

class Driver {
public:
    explicit Driver(const reflex::Input in) : lexer(in), parser(new yy::parser(lexer, &root)) { root = nullptr; }
    ~Driver() { delete parser; }
    XML::Tag* parse() {
        parser->set_debug_level(1);
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
private:
    yy::Lexer lexer;
    yy::parser *parser;
    XML::Tag *root;
};

void generate_code(XML::Tag *root) {
  
}

int main(int argc, char **argv)
{
    XML::Tag* root;
    if (optind < argc) {
        const char* path = argv[optind];
        std::cerr << "Reading from file " << path << std::endl;
        FILE *f = fopen(path, "r");
        if (! f) {
            std::cerr << "Open failed on '" << path << "'" << std::endl;
            exit(5);
        }
        std::cerr << "Opened " << argv[optind] << std::endl;
        Driver driver(f);
        root = driver.parse();
    } else {
        std::cerr << "Reading from stdin" << std::endl;
        Driver driver(&std::cin);
        root = driver.parse();
    }
    if (root != nullptr) {
        std::cerr << "Parsed!" << std::endl;
    } else {
        std::cerr << "Extracted root was nullptr" << std::endl;
        exit(1);
    }
}