#ifndef PLD_COMP_APPEL_H
#define PLD_COMP_APPEL_H

#include "Expression.h"
#include <string>
#include <list>

using namespace std;

class Appel {

public:
	Appel() {}
	Appel(string);
	Appel(string, list<Expression*>);
	~Appel();
	string getId();
	list<Expression*> getExpressions(); 
	void setId(string); 
	void setInstructions (list<Expression*>);
	void addInstruction(Expression* e);
	string toString();
	
protected:
	string id;
	list<Expression*> expressions;

private:

};

#endif //PLD_COMP_INSTRUCTION_H
