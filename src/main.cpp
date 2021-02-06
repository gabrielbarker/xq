#include "XML.hpp"
#include "Parser.hpp"
#include <unistd.h>
#include <iostream>

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
        Parser parser(f);
        root = parser.parse();
        root->print();
    } else {
        std::cerr << "Reading from stdin" << std::endl;
        Parser parser(&std::cin);
        root = parser.parse();
        root->print();
    }
    if (root != nullptr) {
        std::cerr << "Parsed!" << std::endl;
    } else {
        std::cerr << "Extracted root was nullptr" << std::endl;
        exit(1);
    }
}