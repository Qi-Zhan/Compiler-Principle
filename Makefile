CXX = clang++


all: main.cc
	make -C ast all
	$(CXX) ./ast/lex.yy.cc ./ast/parse.tab.cc ./ast/ast.cc main.cc ./sem/sem.cc ./gen/gen.cc `llvm-config --cxxflags --ldflags --system-libs --libs core`  -o  SCC

clean:
	make -C ast clean
	rm -f SCC

cleant:
	rm -f output.o
	rm -f a.out
	rm -f test.o

	