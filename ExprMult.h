#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"
#include "Fonction.h"
#include "Enum.h"

using namespace std;

class ExprMult : public Expression{
	public:
		ExprMult() {};
		ExprMult(Expression* e1, Expression *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprMult() {};
		string buildIR(CFG *cfg);
		string toString();
		int eval();
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Expression *expr1;
		Expression *expr2;
};
