#ifndef PLD_COMP_DEFINITION_H
#define PLD_COMP_DEFINITION_H

#include <iostream>
#include <string>
#include "Affectation.h"
#include <utility>
#include <map>

using namespace std;

class Definition : public Affectation {

public:

	Definition(RightValue *r, LeftValue *l, string t):Affectation(r, l, t) {};
	~Definition() {};
     string toString();
     int getClassName();
     string genererCodeAssembleur(map<string, pair<int, int>>*);
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

