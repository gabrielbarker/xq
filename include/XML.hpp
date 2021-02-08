#pragma once

#include <string>
#include <map>
#include <vector>

namespace XML
{
  class Tag
  {
  public:
    Tag(std::string name, std::map<std::string, std::string> attributes, std::string value);
    Tag(std::string name, std::map<std::string, std::string> attributes, std::vector<XML::Tag*> children);
    std::string getName();
    std::string getValue();
    std::map<std::string, std::string> getAttributes();
    std::vector<XML::Tag*> getChildren();

  private:
    std::string name;
    std::string value;
    std::map<std::string, std::string> attributes;
    std::vector<XML::Tag*> children;
  };

  class Attributes
  {
  public:
    std::string get(std::string name);
    void set(std::string name, std::string value);
    std::map<std::string, std::string> map();

  private:
    std::map<std::string, std::string> attributes;
  };

  class Children
  {
  public:
    void add(XML::Tag* tag);
    std::vector<XML::Tag*> tags();

  private:
    std::vector<XML::Tag*> children;
  };

  class Words
  {
  public:
    void add(std::string s);
    std::string string();

  private:
    std::string str;
  };
} // namespace XML
