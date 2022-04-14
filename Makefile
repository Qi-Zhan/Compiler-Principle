all: main.cpp
	make -C ast all
	clang++ ./ast/lex.yy.c ./ast/parse.tab.c main.cpp -o  SSC

# ast:
	

clean:
	make -C ast clean
	rm SSC 
	