#pragma once

#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class Expression {
	public:
		Expression() {};
		virtual ~Expression() {};
		virtual int genererCodeAssembleur(map<string, pair<int, int>> *, string *codeAss) =0;
		virtual string toString() =0;
		virtual int eval() =0;
	
	protected:
};
