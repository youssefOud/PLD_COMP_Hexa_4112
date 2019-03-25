#include "ExprMult.h"

using namespace std;

string ExprMult::genererCodeAssembleur(map<string, pair<int, int>> *st){
	return "";
}

string ExprMult::toString (){
	return " de valeur "+to_string(eval())+"Expression 1 "+expr1->toString()+" Expression 2 "+expr2->toString();
}

int ExprMult::eval(){
	return expr1->eval()*expr2->eval();
}

void ExprMult::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings){
	expr1->analyse(staticAnalysis,errors,warnings);
	expr2->analyse(staticAnalysis,errors,warnings);
}
