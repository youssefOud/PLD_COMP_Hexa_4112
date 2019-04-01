#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"

using namespace std;

class ExprNeg : public Instruction{
	public:
		ExprNeg() {};
		ExprNeg(Instruction* e) :expr(e){};
		virtual ~ExprNeg() {};
		int genererCodeAssembleur(map<string, pair<int, int>> *, string *codeAss);
		string toString();
		int eval();
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Instruction *expr;
};
