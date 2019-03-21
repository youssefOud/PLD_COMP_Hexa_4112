#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <iostream>
#include <string>

using namespace std;

class Instruction;
class Declaration : public Instruction {

public:
    Declaration(string nomVar, string varType);
    ~Declaration();

    void setId(string nV);
    string getId();

    void setType(int t);
    int getType();
    
   string stringifyType();
	string toSmallString();
    string toString();
	int convertTypeToInt(string);
	int getClassName();
    
private:
    string id;
    int type;
};

#endif //PLD_COMP_DECLARATION_H
