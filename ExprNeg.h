#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Instruction.h"
#include "ExprSimple.h"
#include "ExprMult.h"
#include "RightValueNbr.h"

using namespace std;

class ExprNeg : public Instruction
{
public:
    ExprNeg() {};
    ExprNeg(Instruction* e) :expr(e) {};
    virtual ~ExprNeg() {};
    string toString();
    int eval();
    int getClassName(){ return 8; };
    virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType) ;
    virtual string buildIR(CFG *cfg);
    Instruction * getExpr(){ return expr; }
    virtual bool estCst(list<string> & opti);

protected:
    Instruction *expr;
};
