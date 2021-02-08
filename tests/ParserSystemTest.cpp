#include "Parser.hpp"
#include "XML.hpp"
#include "UnitTest++/UnitTest++.h"
#include <string>
#include <map>
#include <vector>

SUITE(ParserSystemTest)
{
  class ParserFixture
  {
  public: 
    XML::Tag* parseFile(std::string path) 
    {
      FILE *f = fopen(path.c_str(), "r");
      REQUIRE CHECK(f != nullptr);
      Parser parser(f);
      XML::Tag* root = parser.parse();
      REQUIRE CHECK(root != nullptr);
      return root;
    } 

    void checkNameAndValueForTag(std::string name, std::string value, XML::Tag* tag) 
    {
      REQUIRE CHECK_EQUAL(name, tag->getName());
      REQUIRE CHECK_EQUAL(value, tag->getValue());
    }
  };
  
  TEST_FIXTURE(ParserFixture, parseSimpleXML_returnsCorrectTagRoot)
  {
    XML::Tag* root = parseFile("tests/test_data/simple.xml");
    REQUIRE CHECK_EQUAL(root->getName(), "meal");

    std::vector<XML::Tag*> children = root->getChildren();
    checkNameAndValueForTag("nationality", "french", children[0]);
    checkNameAndValueForTag("type", "stew", children[1]);
    checkNameAndValueForTag("vegetarian", "true", children[2]);
    checkNameAndValueForTag("name", "VegetableStew", children[3]);
  }
}