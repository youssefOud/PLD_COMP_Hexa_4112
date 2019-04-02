#include "AffectationSimple.h"
#include <vector>


std::string AffectationSimple::toString() 
{
    return "AffectationSimple Expression "+expr->toString()+" LeftValue "+left->toString()+"\n";
}

int AffectationSimple::getClassName(){
	return 3;
}

string AffectationSimple::buildIR (CFG* cfg){
	string r = expr->buildIR(cfg);
	string l = left->buildIR(cfg);
	vector<string> params;
	params.push_back(l);
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}

