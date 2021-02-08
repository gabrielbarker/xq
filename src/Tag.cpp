#include "XML.hpp"
#include <iostream>

XML::Tag::Tag(std::string name, std::map<std::string, std::string> attributes, std::string value) {
  this->name = name;
  this->attributes = attributes;
  this->value = value;
}

XML::Tag::Tag(std::string name, std::map<std::string, std::string> attributes, std::vector<XML::Tag*> children) {
  this->name = name;
  this->attributes = attributes;
  this->children = children;
}

void XML::Tag::print()
{
  std::cout << "open: " << this->name << std::endl;
  std::map<std::string, std::string>::iterator it;

  for (it = this->attributes.begin(); it != this->attributes.end(); it++)
  {
    std::cout << it->first    // string (key)
              << ": "
              << it->second   // string's value 
              << std::endl;
  }
  for (size_t i = 0; i < this->children.size(); i++)
  {
    this->children[i]->print();
  }
  if (this->children.size() == 0) {
    std::cout << "value: " << this->value << std::endl;
  }
}