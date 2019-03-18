#pragma once

#include <string.h>
#include <iostream>
#include "RightValue.h"

using namespace std;

class RightValueId : public RightValue {
	public:
		RightValueId() {}
		RightValueId(string id) : RightValue(id,0) {cout<<"rightValueId constr"<<endl; };
		~RightValueId() {};
		
		string getId() {return id; };
		int getNbr() {return 0; };
};
