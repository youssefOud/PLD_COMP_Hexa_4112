#pragma once

#ifndef PLD_COMP_AFFECTATION_H
#define PLD_COMP_AFFECTATION_H

#include <iostream>
#include <string>
#include "Instruction.h"
#include <utility>
#include <map>
#include "Expression.h"
#include "Enum.h"

using namespace std;

class Affectation : public Instruction {

public:

	Affectation(Expression *e, LeftValue *l, string t);
	Affectation();
	virtual ~Affectation();
    	virtual string toString() {return "Affectation"; };
    	virtual int getClassName()=0;
	Type getType();	
	void setType(Type t);
	
	Expression *getExpr();
    LeftValue *getLeft();	
Type convertTypeToInt(string);
	virtual string buildIR(CFG *cfg) = 0;
	//virtual string createNewVar()=0;
  
  

protected:
	Type type;
	Expression *expr;
	LeftValue *left;

private:
	

};

#endif //PLD_COMP_AFFECTATION_H

