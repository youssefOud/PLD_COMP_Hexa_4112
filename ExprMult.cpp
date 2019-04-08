#include "ExprMult.h"

using namespace std;

string ExprMult::toString (){
	return " de valeur "+to_string(eval())+"Expression 1 "+expr1->toString()+" Expression 2 "+expr2->toString();
}

int ExprMult::eval(){
	return expr1->eval()*expr2->eval();
}

void ExprMult::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes, bool returnType) {
	expr1->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
	expr2->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
}

string ExprMult::buildIR(CFG *cfg){
	string var1 = expr1->buildIR(cfg);
	string var2 = expr2->buildIR(cfg);
	string var3 = cfg->create_new_tempvar(Type::INT); //1 pour type int
	vector<string> params;
	params.push_back(var3);
	params.push_back(var1);
	params.push_back(var2);
	cfg->addInstruction(IRInstr::Operation::mul, params);
	return var3;
}

bool ExprMult::estCst(list<string> & opti){
	return expr1->estCst(opti) && expr2->estCst(opti); 
}
