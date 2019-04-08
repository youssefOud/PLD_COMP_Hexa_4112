#pragma once

#ifndef PLD_COMP_RETURN_H
#define PLD_COMP_RETURN_H

#include "Instruction.h"
#include "RightValue.h"
#include <iostream>
#include <string>
#include "Enum.h"

class Instruction;
class Return : public Instruction {

public:
    Return(Instruction * expression):expr(expression) {};
    ~Return();
    Instruction *getExpr();
	std::string toString() { return "Return "+expr->toString(); };
	int getClassName(){return 4;};
	string buildIR(CFG *cfg);
	virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);

private:
    Instruction * expr;

};

#endif //PLD_COMP_BREAK_H
