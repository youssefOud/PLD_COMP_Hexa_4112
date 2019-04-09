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
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
		Instruction * getClause();
		list<Instruction*> * getBlocWhile();
	
	protected:
		Instruction *clause;
		list<Instruction*> blocWhile;
};
