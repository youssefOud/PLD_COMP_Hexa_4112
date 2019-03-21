#ifndef PLD_COMP_RETURN_H
#define PLD_COMP_RETURN_H

#include "Instruction.h"
#include "RightValue.h"
#include <iostream>
#include <string>

class Instruction;
class Return : public Instruction {

public:
    Return(RightValue *r):rightValue(r) {};
    ~Return();
    RightValue *getRightValue();
	std::string toString() { return "Return "+rightValue->toString(); };
	int getClassName(){return 4;};
string genererCodeAssembleur(map<string, pair<int, int>>*);

private:
    RightValue * rightValue;

};

#endif //PLD_COMP_BREAK_H
