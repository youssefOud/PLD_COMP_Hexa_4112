#pragma once

#include <string.h>
#include <iostream>
#include "RightValue.h"

using namespace std;

class RightValueNbr : public RightValue {
	public:
		RightValueNbr() {}
		RightValueNbr(int nbr) : RightValue("",nbr) {cout<<"rightValueNbr constr"<<endl; };
		~RightValueNbr() {};
		
		string getId() {return ""; };
		int getNbr() {cout<<"rightValueNbr getNbr"<<endl; return nbr; };
};
