#ifndef PLD_COMP_INSTRUCTION_H
#define PLD_COMP_INSTRUCTION_H

#include "Enum.h"
#include <string>
#include "LeftValue.h"
#include "RightValue.h"
#include <utility>
#include <map>
#include "CFG.h"
#include "IRInstr.h"


using namespace std;

class Instruction {

public:

	Instruction();
	virtual ~Instruction();
  virtual string toString() {return "instruction"; };
  virtual int getClassName()=0;
  virtual string genererCodeAssembleur(map<string, pair<int, int>> *) =0;
  //virtual string getId();
  //virtual int getType();
  //virtual RightValue *getRight();
  //virtual LeftValue *getLeft();	

protected:

private:

};

#endif //PLD_COMP_INSTRUCTION_H
