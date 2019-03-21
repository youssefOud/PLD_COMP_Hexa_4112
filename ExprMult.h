#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"

using namespace std;

class ExprMult : public Expression{
	public:
		ExprMult() {};
		virtual ~ExprMult() {};
		string genererCodeAssembleur(map<string, pair<int, int>> *);
		string toString();
	
	protected:
		Expression *expr1;
		Expression *expr2;
};
