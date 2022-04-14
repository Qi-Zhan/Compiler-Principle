all : lex.yy.c parse.tab.cc

parse.tab.cc, parse.tab.h: parse.y
	bison --defines=parse.tab.h -o parse.tab.cc parse.y

lex.yy.c: scanner.l parse.tab.h
	flex -o lex.yy.cc scanner.l 

clean:
	rm lex.yy.cc parse.tab.cc parse.tab.h