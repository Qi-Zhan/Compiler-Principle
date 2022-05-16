CXX = clang++
CONFIG = `llvm-config-12 --cxxflags --ldflags --system-libs --libs core`

all: main.cc gen.o
	make -C ast all
	$(CXX) ./ast/lex.yy.cc ./ast/parse.tab.cc ./ast/ast.cc main.cc ./sem/sem.cc ./vis/visualizeAST.cc gen.o $(CONFIG)  -o  SCC

gen.o: ./gen/gen.cc
	$(CXX) $(CONFIG)  -c ./gen/gen.cc

clean:
	make -C ast clean
	rm -f SCC
	rm -f gen.o
	rm -f out.dot
	rm -f out.png
cleant:
	rm -f output.o
	rm -f a.out
	rm -f test.o
	rm -f mytest.ll

	