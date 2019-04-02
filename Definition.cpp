#include "Definition.h"
#include <string>
#include <vector>


std::string Definition::toString() 
{
    return "Definition Expression "+expr->toString()+" LeftValue "+left->toString()+ " Type "+to_string(type)+"\n";
}


int Definition::getClassName(){
	return 2;
}

string Definition::buildIR (CFG* cfg){
	string r = expr->buildIR(cfg);
	string l = left->buildIR(cfg);
	vector<string> params;
	params.push_back(l);
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}

