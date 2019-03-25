#include "AffectationSimple.h"



std::string AffectationSimple::toString() 
{
    return "AffectationSimple Expression "+expr->toString()+" LeftValue "+left->toString()+"\n";
}

int AffectationSimple::getClassName(){
	return 3;
}

string AffectationSimple::genererCodeAssembleur(map<string, pair<int, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " + to_string(offset) + "(%rbp), %rax\r\n";
	codeAss += "movq %rax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
	return codeAss;
}
