#include "XML.hpp"

void XML::Children::add(XML::Tag* tag) {
  this->children.push_back(tag);
}

std::vector<XML::Tag*> XML::Children::tags() {
  return this->children;
}
