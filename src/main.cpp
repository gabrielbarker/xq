#include "XML.hpp"
#include "Parser.hpp"
#include <unistd.h>
#include <iostream>

void printTag(XML::Tag* root) {
    std::cout << "open: " << root->getName() << std::endl;
    
    std::map<std::string, std::string>::iterator it;
    std::map<std::string, std::string> attributes = root->getAttributes();
    
    for (it = attributes.begin(); it != attributes.end(); it++)
    {
    std::cout << it->first    // string (key)
                << ": "
                << it->second   // string's value 
                << std::endl;
    }
    std::cout << "after loop" << std::endl;
    for (size_t i = 0; i < root->getChildren().size(); i++)
    {
        printTag(root->getChildren()[i]);
    }
    if (root->getChildren().size() == 0) {
        std::cout << "value: " << root->getValue() << std::endl;
    }
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
        Parser parser(f);
        root = parser.parse();
        printTag(root);
    } else {
        std::cerr << "Reading from stdin" << std::endl;
        Parser parser(&std::cin);
        root = parser.parse();
        printTag(root);
    }
    if (root != nullptr) {
        std::cerr << "Parsed!" << std::endl;
    } else {
        std::cerr << "Extracted root was nullptr" << std::endl;
        exit(1);
    }
}