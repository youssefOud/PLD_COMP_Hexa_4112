ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP


default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o antlr4  expr.g4
	clang++ -DTRACE -g -std=c++11 -I antlr4/ -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp antlr4/*.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

test: test.py
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o antlr4  expr.g4
	clang++ -DTRACE -g -std=c++11 -I antlr4/ -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp antlr4/*.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
	python ./test.py

debug:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp -o antlr4  expr.g4
	clang++ -DTRACE -g -std=c++11 -DDEBUG_ENABLE -I antlr4/ -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp antlr4/*.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

.PHONY: clean
clean : 
	rm -f *.o *.exe exe exe-test

