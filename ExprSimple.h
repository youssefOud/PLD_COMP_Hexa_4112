#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Instruction.h"
#include "RightValue.h"
#include "Enum.h"

using namespace std;

class ExprSimple : public Instruction
{
public:
    ExprSimple() {};
    ExprSimple(RightValue* r) :right(r) {};
    virtual ~ExprSimple() {};
    string buildIR(CFG *cfg);
    string toString();
    int eval();
    int getClassName(){ return 9; };
    void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
    virtual bool estCst(list<string> & opti);

protected:
    RightValue * right;
};
