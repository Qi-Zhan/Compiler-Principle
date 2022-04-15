all: main.cc
	make -C ast all
	clang++ ./ast/lex.yy.cc ./ast/parse.tab.cc ./ast/ast.cc main.cc -o  SSC

# ast:
	

clean:
	make -C ast clean
	rm SSC 
	