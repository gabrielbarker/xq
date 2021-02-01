#include "xml.hpp"

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