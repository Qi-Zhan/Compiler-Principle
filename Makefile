all: main.cpp
	make -C ast all
	clang++ ./ast/lex.yy.cc ./ast/parse.tab.cc main.cpp -o  SSC

# ast:
	

clean:
	make -C ast clean
	rm SSC 
	