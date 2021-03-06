#pragma once

#ifndef PLD_COMP_DECLARATION_H
#define PLD_COMP_DECLARATION_H

#include "Instruction.h"
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include "Enum.h"

using namespace std;

class Instruction;
class Declaration : public Instruction
{

public:
    Declaration(string nomVar, string varType);
    ~Declaration();

    void setId(string nV);
    string getId();

    void setType(Type t);
    Type getType();

    string stringifyType();
    string toSmallString();
    string toString();
    Type convertTypeToInt(string);
    int getClassName();
    string buildIR(CFG *cfg);
    virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
    virtual bool estCst(list<string> & opti);

private:
    string id;
    Type type;
};

#endif //PLD_COMP_DECLARATION_H
