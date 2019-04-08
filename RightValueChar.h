#pragma once

#include <string.h>
#include <iostream>
#include "RightValue.h"

using namespace std;

class RightValueChar : public RightValue {
	public:
		RightValueChar() {}
		RightValueChar(char c) : RightValue("",c) {};
		~RightValueChar() {};
		string toString() { return "RightValueChar "+to_string(nbr)+"\n";}
		string getId() {return ""; };
		int getNbr() { return nbr; };
		virtual bool estCst(list<string> & opti) { return true;};
};
