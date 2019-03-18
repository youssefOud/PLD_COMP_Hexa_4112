#ifndef PLD_COMP_RETURN_H
#define PLD_COMP_RETURN_H

#include "Instruction.h"
#include "RightValue.h"
#include <iostream>
#include <string>

class Instruction;
class Return : public Instruction {

public:
    Return(RightValue *r):expression(r) {};
    ~Return();
    RightValue *getExpression();
	std::string toString() { return "Return "+expression->toString(); };

private:
    RightValue *expression;

};

#endif //PLD_COMP_BREAK_H
