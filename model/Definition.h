#ifndef PLD_COMP_DEFINITION_H
#define PLD_COMP_DEFINITION_H

#include <iostream>
#include <string>
#include "Affectation.h"


class Definition : public Affectation {

public:

	Definition();
	~Definition();
    virtual std::string toString() = 0;
  
protected:

private:

};

#endif //PLD_COMP_DEFINITION_H

