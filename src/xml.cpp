#include "xml.hpp"
#include <iostream>

namespace XML
{
  void Tag::setName(std::string name)
  {
    this->name = name;
  }
  void Tag::setValue(std::string value)
  {
    this->value = value;
  }
  void Tag::setAttributes(std::map<std::string, std::string> attributes)
  {
    this->attributes = attributes;
  }
  void Tag::setChildren(std::vector<XML::Tag*> children)
  {
    this->children = children;
  }
  void Tag::print()
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
}; // namespace XML