#ifndef PLD_COMP_DEFINITION_H
#define PLD_COMP_DEFINITION_H

#include <iostream>
#include <string>
#include "Affectation.h"
using namespace std;

class Definition : public Affectation {

public:

	Definition(RightValue *r, LeftValue *l, string t):Affectation(r, l, t) {};
	~Definition() {};
     string toString() {return "AffectationSimple RightValue "+right->toString()+" LeftValue "+left->toString()+ " Type "+to_string(type)+"\n"; };
     int getClassName() {return 2;};
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

