

all: ./ast/lex.yy.c ./ast/parse.tab.c main.cpp
	clang++ ./ast/lex.yy.c ./ast/parse.tab.c main.cpp --target=i686-pc-mingw32 -o  Spascal

./ast/lex.yy.c, ./ast/parse.tab.c: ./ast/makefile
	cd ./ast  
	make  
	cd..


clean:
	rm Spascal.exe