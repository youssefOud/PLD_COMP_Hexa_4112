#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"
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
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Instruction *expr1;
		Instruction *expr2;
};
