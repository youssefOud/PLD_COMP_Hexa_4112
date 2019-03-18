#include "Affectation.h"

Affectation::~Affectation()
{
	
}

RightValue *Affectation::getRight() {
    return right;
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