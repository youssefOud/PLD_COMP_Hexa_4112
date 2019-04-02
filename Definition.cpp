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

string Definition::genererCodeAssembleur(map<string, pair<Type, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " + to_string(offset) + "(%rbp), %rax\r\n";
	codeAss += "movq %rax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
	return codeAss;
}

string Definition::buildIR (CFG* cfg){
	cout << "build IR Definition " << endl; 
	string r = expr->buildIR(cfg);
	string l = left->buildIR(cfg);
	vector<string> params;
	params.push_back(l);
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	cout << "Fin build IR Definition " << endl; 
	return r;
}

