#pragma once

#ifndef PLD_COMP_AFFECTATION_SIMPLE_H
#define PLD_COMP_AFFECTATION_SIMPLE_H

#include <iostream>
#include <string>
#include "Affectation.h"
#include <utility>
#include <map>
#include "Expression.h"

using namespace std;

class AffectationSimple : public Affectation {

public:

	AffectationSimple(Expression *e, LeftValue *l, string t) : Affectation(e, l, t) {};
	~AffectationSimple() {} ;
     	string toString();
     	int getClassName();
	string buildIR(CFG *cfg);
    	string genererCodeAssembleur(map<string, pair<Type, int>>*);
	//string createNewVar();
  
protected:

private:

};

#endif //PLD_COMP_AFFECTATION_SIMPLE_H

