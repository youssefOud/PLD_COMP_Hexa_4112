#ifndef PLD_COMP_AFFECTATION_H
#define PLD_COMP_AFFECTATION_H

#include <iostream>
#include <string>
#include "Instruction.h"
#include "LeftValue.h"
#include "RightValue.h"


class Affectation : public Instruction {

public:

	Affectation(RightValue *r, LeftValue *l, int t):right(r), left(l), type(t)  {};
	Affectation();
	~Affectation();
    virtual std::string toString() = 0;
    
	int getType();	
	void setType(int t);
	
	RightValue *getRight();
    LeftValue *getLeft();	
  
  

protected:

private:
	int type;
	RightValue *right;
	LeftValue *left;

};

#endif //PLD_COMP_AFFECTATION_H

