#include "Affectation.h"

Affectation::Affectation(Instruction *e, LeftValue *l, string t) {
	expr=e;
	left=l;
	type=convertTypeToInt(t);
 	
}

Affectation::~Affectation()
{
	
}

Instruction *Affectation::getExpr() {
    return expr;
}

LeftValue *Affectation::getLeft() {
    return left;
}

Type Affectation::getType(){
	return type;
}

void Affectation::setType(Type t){
	type = t;
}

Type Affectation::convertTypeToInt(string nom) {
	Type t = VIDE;
	if (nom == "int") t = INT;
	else if (nom == "void") t = VOID;
	else if (nom == "char") t = CHAR;
	return t; 
}

