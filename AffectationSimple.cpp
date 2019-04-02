#include "AffectationSimple.h"
#include <vector>


std::string AffectationSimple::toString() 
{
    return "AffectationSimple Expression "+expr->toString()+" LeftValue "+left->toString()+"\n";
}

int AffectationSimple::getClassName(){
	return 3;
}

string AffectationSimple::genererCodeAssembleur(map<string, pair<Type, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " + to_string(offset) + "(%rbp), %rax\r\n";
	codeAss += "movq %rax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
	return codeAss;
}

string AffectationSimple::buildIR (CFG* cfg){
	cout << "build IR AffectationSimple " << endl; 
	string r = expr->buildIR(cfg);
	string l = left->buildIR(cfg);
	vector<string> params;
	params.push_back(l);
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}

