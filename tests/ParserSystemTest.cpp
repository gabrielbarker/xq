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
  public: XML::Tag* parseFile(std::string path) 
    {
      FILE *f = fopen(path.c_str(), "r");
      REQUIRE CHECK(f != nullptr);
      Parser parser(f);
      XML::Tag* root = parser.parse();
      CHECK(root != nullptr);
      return root;
    }
  };
  
  TEST_FIXTURE(ParserFixture, parseSimpleXML_returnsCorrectTagRoot)
  {
    XML::Tag* root = parseFile("tests/test_data/simple.xml");
  }
}