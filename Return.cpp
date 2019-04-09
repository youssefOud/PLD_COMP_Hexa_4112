#include "Return.h"
#include <string>
#include <vector>

Return::~Return()
{

}

Instruction *Return::getExpr() {
    return expr;
}

string Return::buildIR(CFG *cfg){
	//TODO
	string r = expr->buildIR(cfg);
	vector<string> params;
	params.push_back("!rax");
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}

void Return::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType){
	expr->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
}

bool Return::estCst(list<string> & opti){
	if(expr->getClassName() != 9){ //Si ce n'est pas une expression simple
		return expr->estCst(opti);		
	}
	return false; // Si c'est une expression simple, aucune optimisation n'est possible
}
