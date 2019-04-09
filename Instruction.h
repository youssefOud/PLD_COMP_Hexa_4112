#pragma once
#ifndef PLD_COMP_INSTRUCTION_H
#define PLD_COMP_INSTRUCTION_H

#include "Enum.h"
#include <string>
#include "LeftValue.h"
#include "RightValue.h"
#include <utility>
#include <map>
#include <vector>
#include <list>
#include "CFG.h"
#include "IRInstr.h"


using namespace std;

class Instruction {

public:

	Instruction();
	virtual ~Instruction();
  	virtual string toString() {return "instruction"; };
 	virtual int getClassName(){return -1;};
	virtual int eval() {return 0;};
	virtual string buildIR(CFG *cfg) = 0;
	virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & 	prototypes,bool returnType) {};
	virtual bool estCst(list<string> & opti) { return false;};
	virtual int getNbLine(){return nbLine;};
	virtual void setNbLine(int l){nbLine=l;};

protected:
	int nbLine;

private:

};

#endif //PLD_COMP_INSTRUCTION_H
