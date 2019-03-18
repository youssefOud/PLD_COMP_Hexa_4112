#ifndef PLD_COMP_AFFECTATION_SIMPLE_H
#define PLD_COMP_AFFECTATION_SIMPLE_H

#include <iostream>
#include <string>
#include "Affectation.h"


class AffectationSimple : public Affectation {

public:

	AffectationSimple();
	~AffectationSimple();
    virtual std::string toString() = 0;
  
protected:

private:

};

#endif //PLD_COMP_AFFECTATION_SIMPLE_H

