#include "Affectation.h"

Affectation::Affectation(Expression *e, LeftValue *l, string t) {
	expr=e;
	left=l;
	type=convertTypeToInt(t);
 	
}

Affectation::~Affectation()
{
	
}

Expression *Affectation::getExpr() {
    return expr;
}

LeftValue *Affectation::getLeft() {
    return left;
}

int Affectation::getType(){
	return type;
}

void Affectation::setType(int t){
	type = t;
}

int Affectation::convertTypeToInt(string nom) {
	Type t = VIDE;
	if (nom == "") t = VIDE;
	else if (nom == "int") t = INT;
	return t; 
}

