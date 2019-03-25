#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"
#include "RightValue.h"

using namespace std;

class ExprSimple : public Expression{
	public:
		ExprSimple() {};
		ExprSimple(RightValue* r) :right(r){};
		virtual ~ExprSimple() {};
		int genererCodeAssembleur(map<string, pair<int, int>> *, string *codeAss);
		string toString();
		int eval();
	
	protected:
		RightValue * right;
};
