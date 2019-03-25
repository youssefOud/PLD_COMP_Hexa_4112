#include "ExprSimple.h"

using namespace std;

int ExprSimple::genererCodeAssembleur(map<string, pair<int, int>> *st, string *codeAss){
	if(!right->getId().empty()){ //l'rightession simple est un id
		return st->find(right->getId())->second.second;
	}
	else{
		st->insert( make_pair("temp"+to_string(nextFree), make_pair(1, nextFree) )); //1 correspond au type int dans enumeration
		*codeAss+= "movq $" + to_string(right->getNbr()) + ", " + to_string(nextFree) + "(%rbp)\r\n";
		nextFree-=8;
		return nextFree+8; 
	}
}

string ExprSimple::toString (){
	return "Right Value " + right->toString();
}

int ExprSimple::eval(){
	return right->getNbr();
}
