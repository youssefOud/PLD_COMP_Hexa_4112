#include "Definition.h"
#include <string>


std::string Definition::toString() 
{
    return "Definition Expression "+expr->toString()+" LeftValue "+left->toString()+ " Type "+to_string(type)+"\n";
}


int Definition::getClassName(){
	return 2;
}

string Definition::genererCodeAssembleur(map<string, pair<int, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " + to_string(offset) + "(%rbp), %rax\r\n";
	codeAss += "movq %rax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
	return codeAss;
}
