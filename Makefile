ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP

default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o antlr4  expr.g4
	clang++ -DTRACE -g -std=c++11 -I antlr4/ -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp antlr4/*.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

