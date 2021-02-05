defintion:
	bison -b ../../include/parser/xml -d xml.yxx
	reflex --bison-cc --bison-locations --header-file=../../include/parser/xml.yy.h --outfile=xml.yy.cpp  xml.lxx
clean:
	rm -r xml.yy.cpp
	rm -r ../../include/parser
	mkdir ../../include/parser