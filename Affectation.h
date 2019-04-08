#pragma once

#ifndef PLD_COMP_AFFECTATION_H
#define PLD_COMP_AFFECTATION_H

#include <iostream>
#include <string>
#include "Instruction.h"
#include <utility>
#include <map>
#include "Enum.h"

using namespace std;

class Affectation : public Instruction {

public:

	Affectation(Instruction *e, LeftValue *l, string t);
	Affectation();
	virtual ~Affectation();
    	virtual string toString() {return "Affectation"; };
    	virtual int getClassName()=0;
	Type getType();	
	void setType(Type t);
	
	Instruction *getExpr();
    	LeftValue *getLeft();	
	Type convertTypeToInt(string);
	virtual string buildIR(CFG *cfg) = 0;
	virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & 	prototypes,bool returnType) {};
  
  

protected:
	Instruction *expr;
	Type type;
	LeftValue *left;

private:
	

};

#endif //PLD_COMP_AFFECTATION_H

