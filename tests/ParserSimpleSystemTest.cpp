#include "Parser.hpp"
#include "XML.hpp"
#include "UnitTest++/UnitTest++.h"
#include <string>

SUITE(ParserSystemTest)
{
  class ParserFixture
  {
  public: void parseFile(std::string path) 
    {
      FILE *f = fopen(path.c_str(), "r");
      REQUIRE CHECK(f != nullptr);
      Parser parser(f);
      XML::Tag* root = parser.parse();
      CHECK(root != nullptr);
    }
  };
  
  TEST_FIXTURE(ParserFixture, parseSimpleXML_parsesCorrectly)
  {
    parseFile("tests/test_data/simple.xml");
  }

  TEST_FIXTURE(ParserFixture, parsePlantsXML_parsesCorrectly)
  {
    parseFile("tests/test_data/plants.xml");
  }

  TEST_FIXTURE(ParserFixture, parseSpecialXML_parsesCorrectly)
  {
    parseFile("tests/test_data/special.xml");
  }
  
  TEST_FIXTURE(ParserFixture, parseCommentXML_parsesCorrectly)
  {
    parseFile("tests/test_data/comment.xml");
  }
  
  TEST_FIXTURE(ParserFixture, parseAttributesXML_parsesCorrectly)
  {
    parseFile("tests/test_data/attributes.xml");
  }
}