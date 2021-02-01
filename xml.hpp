#pragma once

#include <string>
#include <map>
#include <vector>

namespace XML
{

  class Attributes
  {
  public:
    std::string get(std::string name);
    void set(std::string name, std::string value);
    std::map<std::string, std::string> map();

  private:
    std::map<std::string, std::string> attributes;
  };

  class Tag
  {
  public:
    void setName(std::string name);
    void setValue(std::string value);
    void setAttributes(std::map<std::string, std::string> attributes);
    void setChildren(std::vector<XML::Tag*> children);

  private:
    std::string name;
    std::string value;
    std::map<std::string, std::string> attributes;
    std::vector<XML::Tag*> children;
  };

  class Children
  {
  public:
    void add(XML::Tag* tag);
    std::vector<XML::Tag*> tags();

  private:
    std::vector<XML::Tag*> children;
  };
}; // namespace XML
