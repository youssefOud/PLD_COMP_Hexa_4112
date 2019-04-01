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

Type Affectation::getType(){
	return type;
}

void Affectation::setType(Type t){
	type = t;
}

Type Affectation::convertTypeToInt(string nom) {
	Type t = Type::VIDE;
	if (nom == "") t = Type::VIDE;
	else if (nom == "int") t = Type::INT;
	return t; 
}

