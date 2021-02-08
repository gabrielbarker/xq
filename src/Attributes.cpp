#include "XML.hpp"

std::string XML::Attributes::get(std::string name) {
  return this->attributes[name];
}

void XML::Attributes::set(std::string name, std::string value) {
  this->attributes[name] = value;
}

std::map<std::string, std::string> XML::Attributes::map() {
  return this->attributes;
}
