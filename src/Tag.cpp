#include "XML.hpp"

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

std::string XML::Tag::getName() {
  return this->name;
}

std::string XML::Tag::getValue() {
  return this->value;
}

std::map<std::string, std::string> XML::Tag::getAttributes() {
  return this->attributes;
}

std::vector<XML::Tag*> XML::Tag::getChildren() {
  return this->children;
}