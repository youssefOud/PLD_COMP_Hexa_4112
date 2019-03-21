#ifndef PLD_COMP_AFFECTATION_SIMPLE_H
#define PLD_COMP_AFFECTATION_SIMPLE_H

#include <iostream>
#include <string>
#include "Affectation.h"

using namespace std;

class AffectationSimple : public Affectation {

public:

	AffectationSimple(RightValue *r, LeftValue *l, string t) : Affectation(r, l, t) {};
	~AffectationSimple() {} ;
     string toString() {return "AffectationSimple RightValue "+right->toString()+" LeftValue "+left->toString()+"\n"; };
     int getClassName() {return 3;};
  
protected:

private:

};

#endif //PLD_COMP_AFFECTATION_SIMPLE_H

