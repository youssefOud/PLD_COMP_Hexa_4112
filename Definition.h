#pragma once

#ifndef PLD_COMP_DEFINITION_H
#define PLD_COMP_DEFINITION_H

#include <iostream>
#include <string>
#include "Affectation.h"
#include <utility>
#include <map>
#include "Expression.h"

using namespace std;

class Definition : public Affectation {

public:

	Definition(Instruction *e, LeftValue *l, string t):Affectation(e, l, t) {};
	~Definition() {};
     string toString();
     int getClassName();
	string buildIR(CFG *cfg);
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

