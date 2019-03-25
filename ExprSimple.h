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
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		RightValue * right;
};
