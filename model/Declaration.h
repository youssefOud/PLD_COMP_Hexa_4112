#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <iostream>
#include <string>

class Instruction;
class Declaration : public Instruction {

public:
    Declaration(std::string nomVar, int varType);
    ~Declaration();

    void setId(std::string nV);
    std::string getId();

    void setType(int t);
    int getType();
    
    std::string stringifyType();
	std::string toSmallString();
    std::string toString();
    
private:
    std::string id;
    int type;
};

#endif //PLD_COMP_DECLARATION_H
