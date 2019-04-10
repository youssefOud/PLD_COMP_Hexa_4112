#pragma once

#include "Fonction.h"
#include "Instruction.h"
#include <string.h>
#include <iostream>

using namespace std;

class ExprMoins : public Instruction
{
public:
    ExprMoins() {};
    ExprMoins(Instruction* e1, Instruction *e2) :expr1(e1), expr2(e2) {};
    virtual ~ExprMoins() {};
    string buildIR(CFG *cfg);
    string toString();
    int eval();
    int getClassName() { return 5; };
    virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
    Instruction * getExpr1(){ return expr1; }
    Instruction * getExpr2() { return expr2; }
    virtual bool estCst(list<string> & opti);

protected:
    Instruction *expr1;
    Instruction *expr2;
};
