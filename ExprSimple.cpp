#include "ExprSimple.h"

using namespace std;

string ExprSimple::genererCodeAssembleur(map<string, pair<int, int>> *st){
	return "";
}

string ExprSimple::toString (){
	return "Right Value " + right->toString();
}

int ExprSimple::eval(){
	return right->getNbr();
}
