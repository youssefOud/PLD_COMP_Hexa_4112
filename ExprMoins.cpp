#include "ExprMoins.h"

using namespace std;

string ExprMoins::genererCodeAssembleur(map<string, pair<int, int>> *st){
	return "";
}

string ExprMoins::toString (){
	return " de valeur "+to_string(eval())+" Expression 1 "+expr1->toString()+" Expression 2 "+expr2->toString() ;
}

int ExprMoins::eval(){
	return expr1->eval()-expr2->eval();
}
