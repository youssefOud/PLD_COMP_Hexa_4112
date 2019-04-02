#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"
#include "Enum.h"

using namespace std;

class ExprPlus : public Expression{
	public:
		ExprPlus() {};
		ExprPlus(Expression* e1, Expression *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprPlus() {};
		string buildIR(CFG *cfg);
		string toString();
		int eval();
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Expression *expr1;
		Expression *expr2;
};
