#pragma once

#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "Instruction.h"
#include "CFG.h"
#include "Enum.h"

using namespace std;

class Expression : public Instruction
{
public:
    Expression() {};
    virtual ~Expression() {};
    virtual string buildIR(CFG *cfg) =0;
    virtual string toString() =0;
    virtual int eval() =0;
    virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings) =0;
    virtual int getClassName() { return 5; };
    virtual string genererCodeAssembleur(map<string, pair<int, int>> *){ return ""; };

protected:
};
