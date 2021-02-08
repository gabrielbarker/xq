#include "XML.hpp"
#include <iostream>

namespace XML
{
  Tag::Tag(std::string name, std::map<std::string, std::string> attributes, std::string value) {
    this->name = name;
    this->attributes = attributes;
    this->value = value;
  }
  
  Tag::Tag(std::string name, std::map<std::string, std::string> attributes, std::vector<XML::Tag*> children) {
    this->name = name;
    this->attributes = attributes;
    this->children = children;
  }

  void Tag::print()
  {
    cout << "open: " << this->name << endl;
    std::map<std::string, std::string>::iterator it;

    for (it = this->attributes.begin(); it != this->attributes.end(); it++)
    {
      cout << it->first    // string (key)
                << ": "
                << it->second   // string's value 
                << endl;
    }
    for (size_t i = 0; i < this->children.size(); i++)
    {
      this->children[i]->print();
    }
    if (this->children.size() == 0) {
      cout << "value: " << this->value << endl;
    }
  }

  std::string Attributes::get(std::string name) {
    return this->attributes[name];
  }

  void Attributes::set(std::string name, std::string value) {
    this->attributes[name] = value;
  }

  std::map<std::string, std::string> Attributes::map() {
    return this->attributes;
  }

  void Children::add(XML::Tag* tag) {
    this->children.push_back(tag);
  }

  std::vector<XML::Tag*> Children::tags() {
    return this->children;
  }

  void Words::add(std::string s) {
    this->str += s;
  }

  std::string Words::string() {
    return this->str;
  }
} // namespace XML
