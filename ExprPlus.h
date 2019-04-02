#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"
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
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Instruction *expr1;
		Instruction *expr2;
};
