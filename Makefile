defintion:
	bison -d parser.yxx
	reflex --bison-cc --bison-locations --header-file xml.lxx
	g++ -I../RE-flex/include -o bin/xml parser.cpp lex.yy.cpp xml.cpp parser.tab.cxx ../RE-flex/lib/libreflex.a
clean:
	rm lex.yy.cpp
	rm lex.yy.h
	rm parser.tab.cxx
	rm parser.tab.hxx
	rm position.hh
	rm stack.hh
	rm location.hh
	rm bin/xml