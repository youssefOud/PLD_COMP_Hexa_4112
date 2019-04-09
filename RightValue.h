#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class RightValue {
	public:
		RightValue();
		RightValue(string id, int nb) : id(id), nbr(nb) {};
		virtual ~RightValue() {};
		virtual string toString() =0;
		virtual string getId() {return id; };
		virtual int getNbr() {return nbr; } ;
		virtual bool estCst(list<string> & opti) { return false;};
	
	protected:
		string id;
		int nbr;
};
