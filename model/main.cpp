#include "LeftValue.h"
#include "RightValueNbr.h"
#include "RightValueId.h"
#include <iostream>

int main () {
	RightValue nbr = RightValueNbr(5);
	cout<<nbr.getNbr()<<endl;

	RightValueId id = RightValueId("Test OK");
	cout<<id.getId()<<endl;
	return 0;
}
