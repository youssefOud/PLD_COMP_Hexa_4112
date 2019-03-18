#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class RightValue {
	public:
		RightValue();
		RightValue(string id, int nb) : id(id), nbr(nb) {cout<<"rightValue constr "<<nbr<<endl;};
		virtual ~RightValue() {};
		
		virtual string getId() {return id; };
		virtual int getNbr() {return nbr; } ;
	
	protected:
		string id;
		int nbr;
};
