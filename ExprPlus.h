#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"

using namespace std;

class ExprPlus : public Expression{
	public:
		ExprPlus() {};
		virtual ~ExprPlus() {};
		string genererCodeAssembleur(map<string, pair<int, int>> *);
		string toString();
	
	protected:
		Expression *expr1;
		Expression *expr2;
};
