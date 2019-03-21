#ifndef PLD_COMP_AFFECTATION_H
#define PLD_COMP_AFFECTATION_H

#include <iostream>
#include <string>
#include "Instruction.h"
#include <utility>
#include <map>

using namespace std;

class Affectation : public Instruction {

public:

	Affectation(RightValue *r, LeftValue *l, string t);
	Affectation();
	virtual ~Affectation();
    virtual string toString() {return "Affectation"; };
    virtual int getClassName()=0;
    
	int getType();	
	void setType(int t);
	
	RightValue *getRight();
    LeftValue *getLeft();	
int convertTypeToInt(string);
        virtual string genererCodeAssembleur(map<string, pair<int, int>> *)=0;
  
  

protected:
	int type;
	RightValue *right;
	LeftValue *left;

private:
	

};

#endif //PLD_COMP_AFFECTATION_H

