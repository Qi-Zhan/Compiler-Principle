all : lex.yy.c parse.tab.c

parse.tab.c, parse.tab.h: parse.y
	bison -d parse.y

lex.yy.c: scanner.l parse.tab.h
	flex scanner.l

clean:
	rm lex.yy.c parse.tab.c parse.tab.h