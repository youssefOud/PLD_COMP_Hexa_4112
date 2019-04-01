#include "CFG.h"


CFG::CFG(Fonction* f) {
	ast = f;
	symbolTable = f->getST();
	nextFreeSymbolIndex = nextFree;
}

void CFG::add_bb(BasicBlock* bb) {
	bbs.push_back(bb);
}

void CFG::genererCodeAssembleur(ostream& o) {
	for(vector <BasicBlock*>::iterator it = this->bbs.begin(); it != this->bbs.end(); it++){
		(*it)->genererCodeAssembleur(o);	
	}

	// Au minimum deux basics blocs dans chaque CFG car ils convergent tous sur un basic bloc qui sera celui du return ou si c'est un void vers une étiquette qui correspondra à l'épilogue
}

// TODO
void CFG::gen_asm_prologue(ostream& o) {
	o << ".globl main" << endl;
}

// TODO
void CFG::gen_asm_epilogue(ostream& o) {
	
}

void CFG::add_to_symbol_table(string name, Type t){
	symbolTable->insert( make_pair(name, make_pair(t, nextFreeSymbolIndex) ));
	nextFreeSymbolIndex -=8;
}

// TODO
string CFG::create_new_tempvar(Type t) {
	string newVarName = "!temp" + to_string(nextFreeSymbolIndex);
	add_to_symbol_table(newVarName, t);
	return newVarName;
}

int CFG::get_var_index(string name) {
	return symbolTable->find(name)->second.second;
}

int CFG::get_var_type(string name) {
	return symbolTable->find(name)->second.first;
}

void CFG::addInstruction (IRInstr::Operation mnemo, vector<string> params){
	//todo
}

int CFG::getNextFreeIndex() {
	return nextFreeSymbolIndex;
}

int CFG::getOffsetFromSymbolTable(string id){
	//todo
	return 0;
}
