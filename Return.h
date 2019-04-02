#pragma once

#ifndef PLD_COMP_RETURN_H
#define PLD_COMP_RETURN_H

#include "Instruction.h"
#include "RightValue.h"
#include <iostream>
#include <string>
#include "Expression.h"
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

private:
    Instruction * expr;

};

#endif //PLD_COMP_BREAK_H
