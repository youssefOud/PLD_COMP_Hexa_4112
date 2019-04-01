#pragma once

#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"

using namespace std;

class ExprMoins : public Expression{
	public:
		ExprMoins() {};
		ExprMoins(Expression* e1, Expression *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprMoins() {};
		string buildIR(CFG *cfg);
		int genererCodeAssembleur(map<string, pair<Type, int>> *, string *codeAss);
		string toString();
		int eval();
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		Expression *expr1;
		Expression *expr2;
};
