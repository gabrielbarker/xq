#include "Parser.hpp"
#include "XML.hpp"
#include "UnitTest++/UnitTest++.h"

SUITE(ParserSystemTest)
{
  TEST(parseSimpleXML_parsesCorrectly)
  {
    FILE *f = fopen("tests/test_data/simple.xml", "r");
    if (! f) {
      std::cerr << "Open file failed" << std::endl;
      exit(5);
    }
    Parser parser(f);
    XML::Tag* root = parser.parse();
    CHECK(root != nullptr);
  }
}