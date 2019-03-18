#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "calc.h"
using namespace antlr4;
using namespace std;
int main(int , const char **) {
	
	//ANTLRInputStream input("int main () { return 42;}");

	cout<<"lecture fichier: "<<endl;
	ifstream myReadFile;
	myReadFile.open("./test/affect.cpp");
	//char output[100];
	string output="";
	string temp;
	if (myReadFile.is_open()) {
		myReadFile >> std::noskipws;
		while (!myReadFile.eof()) {
				getline(myReadFile,temp);
				output = output + temp;
		       // myReadFile >> output;
		}
	}
	myReadFile.close();
	ANTLRInputStream input(output);


	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.function();
	calc visitor;
	visitor.visit(tree);
	//cout<<"Résultat "<<resultat<<endl;
	return 0;
}
