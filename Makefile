complier: lex.yy.c parse.tab.c
	g++ lex.yy.c parse.tab.c -o complier
parse.tab.c, parse.tab.h: parse.y
	bison -d parse.y

lex.yy.c: scanner.l parse.tab.h
	flex lex.yy.c

clean: