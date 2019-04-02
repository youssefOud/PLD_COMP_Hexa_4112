#pragma once
#include "Fonction.h"
#include <string.h>
#include <iostream>
#include "Expression.h"
#include "RightValue.h"
#include "Enum.h"

using namespace std;

class ExprSimple : public Instruction{
	public:
		ExprSimple() {};
		ExprSimple(RightValue* r) :right(r){};
		virtual ~ExprSimple() {};
		string buildIR(CFG *cfg);
		string toString();
		int eval();
		void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings);
	
	protected:
		RightValue * right;
};
