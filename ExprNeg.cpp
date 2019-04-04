#include "ExprNeg.h"

using namespace std;

/*int ExprNeg::genererCodeAssembleur(map<string, pair<int, int>> *st, string *codeAss){
	int offset1 = expr->genererCodeAssembleur(st, codeAss);
	
	
	st->insert( make_pair("temp"+to_string(nextFree), make_pair(1, nextFree) )); //1 correspond au type int dans enumeration

	*codeAss += "movq " + to_string(offset1) + "(%rbp), %rax\r\n";
	*codeAss += "movq %rax, " + to_string(nextFree) + "(%rbp)\r\n";

	nextFree-=8;

	return nextFree+8;

	//movq -16(%rbp), %rax # offset of a is -16
	//addq -24(%rbp), %rax
	//movq %rax, -32(%rbp) 
}*/

string ExprNeg::toString (){
	return " de valeur "+to_string(eval())+"Expression "+expr->toString();
}

int ExprNeg::eval(){
	return -(expr->eval());
}

void ExprNeg::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType) {
	expr->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
}

string ExprNeg::buildIR(CFG *cfg){
	string var = expr->buildIR(cfg);
	string varNeg = cfg->create_new_tempvar(Type::INT);;
	vector<string> params;
	params.push_back(varNeg);
	params.push_back(var);
	cfg->addInstruction(IRInstr::Operation::neg, params);
	return varNeg;

}
