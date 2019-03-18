#ifndef PLD_COMP_INSTRUCTION_H
#define PLD_COMP_INSTRUCTION_H

#include "Enum.h"
#include <string>

class Instruction {

public:

	Instruction();
	virtual ~Instruction();
  virtual std::string toString() {return "instruction"; };

protected:

private:

};

#endif //PLD_COMP_INSTRUCTION_H
