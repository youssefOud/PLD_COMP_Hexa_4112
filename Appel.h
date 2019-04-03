#ifndef PLD_COMP_APPEL_H
#define PLD_COMP_APPEL_H

#include "Expression.h"
#include <string>
#include <list>

using namespace std;

class Appel: public Instruction {

public:
	Appel() {}
	Appel(string);
	Appel(string, list<Instruction*>);
	~Appel();
	string getId();
	list<Instruction*> getExpressions(); 
	void setId(string); 
	void setInstructions (list<Instruction*>);
	void addInstruction(Instruction* e);
	string toString();
	int getClassName(){return 10;};
	virtual int genererCodeAssembleur(map<string, pair<int, int>> *, string *codeAss) {return 0;};
	virtual int eval() {return 0;};
	virtual void analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings) {};
	virtual string buildIR(CFG *cfg) { return ""; };

	
protected:
	string id;
	list<Instruction*> expressions;

private:

};

#endif //PLD_COMP_INSTRUCTION_H
