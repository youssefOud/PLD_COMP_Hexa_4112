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

	AffectationSimple(Instruction *e, LeftValue *l, string t) : Affectation(e, l, t) {};
	~AffectationSimple() {} ;
     string toString();
     int getClassName();
     string genererCodeAssembleur(map<string, pair<int, int>>*);
  
protected:

private:

};

#endif //PLD_COMP_AFFECTATION_SIMPLE_H

