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
		virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);
		virtual bool estCst(list<string> & opti);
		Instruction * getClause();
		list<Instruction*> * getBlocIf();
		list<Instruction*> * getBlocElse();
		virtual bool containsRet(){return ret;};
	
	protected:
		Instruction *clause;
		list<Instruction*> blocIf;
		list<Instruction*> blocElse;
		bool ret=false;
};
