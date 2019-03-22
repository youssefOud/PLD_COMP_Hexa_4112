#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"

using namespace std;

class ExprMoins : public Expression{
	public:
		ExprMoins() {};
		ExprMoins(Expression* e1, Expression *e2) :expr1(e1), expr2(e2){};
		virtual ~ExprMoins() {};
		string genererCodeAssembleur(map<string, pair<int, int>> *);
		string toString();
	
	protected:
		Expression *expr1;
		Expression *expr2;
};