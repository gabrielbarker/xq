#include "XML.hpp"

void XML::Words::add(std::string s) {
  this->str += s;
}

std::string XML::Words::string() {
  return this->str;
}
