CXX = clang++


all: main.cc
	make -C ast all
	$(CXX) ./ast/lex.yy.cc ./ast/parse.tab.cc ./ast/ast.cc main.cc ./sem/sem.cc ./gen/gen.cc `llvm-config --cxxflags --ldflags --system-libs --libs core`  -o  SCC

# ast:
	

clean:
	make -C ast clean
	rm SCC
	