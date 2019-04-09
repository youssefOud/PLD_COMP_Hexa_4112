#pragma once

#include <string.h>
#include <iostream>
#include <list>
#include "Instruction.h"
class BacicBlock;
using namespace std;

class WhileInstruction : public Instruction{
	public:
		WhileInstruction() {};
		WhileInstruction(Instruction* c, list<Instruction*> l);
		virtual ~WhileInstruction();
		string buildIR(CFG *cfg);
		string toString();
		int eval() {return -1; };
		int getClassName(){return 12;};
		virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
		Instruction * getClause();
		list<Instruction*> * getBlocWhile();
		virtual bool estCst(list<string> & opti);
		virtual bool containsRet(){return ret;};
	
	protected:
		Instruction *clause;
		list<Instruction*> blocWhile;
		bool ret=false;
};
