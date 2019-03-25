#include "ExprMult.h"

using namespace std;

int ExprMult::genererCodeAssembleur(map<string, pair<int, int>> *st, string *codeAss){
	int offset1 = expr1->genererCodeAssembleur(st, codeAss);
	int offset2 = expr2->genererCodeAssembleur(st, codeAss);
	
	
	st->insert( make_pair("temp"+to_string(nextFree), make_pair(1, nextFree) )); //1 correspond au type int dans enumeration

	*codeAss += "movq " + to_string(offset1) + "(%rbp), %rax\r\n";
	*codeAss += "imulq " + to_string(offset2) + "(%rbp), %rax\r\n";
	*codeAss += "movq %rax, " + to_string(nextFree) + "(%rbp)\r\n";

	nextFree-=8;

	return nextFree+8;
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
