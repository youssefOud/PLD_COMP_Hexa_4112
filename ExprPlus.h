#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Instruction.h"
#include "Enum.h"

using namespace std;

class ExprPlus : public Instruction{
	public:
		ExprPlus() {};
		ExprPlus(Instruction* e1, Instruction *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprPlus() {};
		string buildIR(CFG *cfg);
		string toString();
		int eval();
		int getClassName(){return 7;};
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType);	

		Instruction * getExpr1() { return expr1;}
		Instruction * getExpr2() { return expr2;}
	
	protected:
		Instruction *expr1;
		Instruction *expr2;
};
