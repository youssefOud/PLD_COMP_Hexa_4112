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

	Definition(Expression *e, LeftValue *l, string t):Affectation(e, l, t) {};
	~Definition() {};
     string toString();
     int getClassName();
	string buildIR(CFG *cfg);
     string genererCodeAssembleur(map<string, pair<Type, int>>*);
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

