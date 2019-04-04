#pragma once

#include "Instruction.h"
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

class IFInstruction : public Instruction {
	public:
		IFInstruction() {};
		IFInstruction(Instruction* c, list<Instruction*> lif, list<Instruction*> lelse);
		virtual ~IFInstruction();
		string buildIR(CFG *cfg);
		string toString();
		int eval() {return -1; };
		int getClassName(){return 11;};
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
		Instruction * getClause();
		list<Instruction*> * getBlocIf();
		list<Instruction*> * getBlocElse();
	
	protected:
		Instruction *clause;
		list<Instruction*> blocIf;
		list<Instruction*> blocElse;
};
