#pragma once

#include <string.h>
#include <iostream>
#include "RightValue.h"

using namespace std;

class RightValueId : public RightValue {
	public:
		RightValueId() {}
		RightValueId(string id) : RightValue(id,0) { };
		~RightValueId() {};
		string toString() { return "RightValueId "+id+"\n";}
		string getId() {return id; };
		int getNbr() {return 0; };
		virtual bool estCst(list<string> & opti) { return false;};
};
