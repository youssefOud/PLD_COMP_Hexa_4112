#pragma once

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

	Definition(Instruction *e, LeftValue *l, string t):Affectation(e, l, t) {};
	~Definition() {};
     string toString();
     int getClassName();
	string buildIR(CFG *cfg);
	virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

