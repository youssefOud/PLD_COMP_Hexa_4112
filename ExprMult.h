#pragma once

#include <string.h>
#include <iostream>
#include "Instruction.h"
#include "Fonction.h"
#include "Enum.h"

using namespace std;

class ExprMult : public Instruction{
	public:
		ExprMult() {};
		ExprMult(Instruction* e1, Instruction *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprMult() {};
		string buildIR(CFG *cfg);
		string toString();
		int eval();
		int getClassName(){return 6;};
		virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes);
		Instruction * getExpr1() { return expr1;}
		Instruction * getExpr2() { return expr2;}
	
	protected:
		Instruction *expr1;
		Instruction *expr2;
};
