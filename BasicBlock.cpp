#include "BasicBlock.h"

BasicBlock::BasicBlock(CFG* cfg_, string entry_label) {
	cfg = cfg_;
	label = entry_label;
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params) {
	IRInstr * newInstr = new IRInstr(this, op, t, params);
	instrs.push_back(newInstr);
}

void BasicBlock::genererCodeAssembleur(ostream &o) {
	cout << "Generation code assembleur : BB" << endl;
	for(vector<IRInstr*>::iterator it = this->instrs.begin(); it != this->instrs.end(); it++){
		(*it)->genererCodeAssembleur(o);	
	}
	cout << "Fin Generation code assembleur : CFG" << endl;
}
