#include "CFG.h"


CFG::CFG(Fonction* ast) {
	ast = ast;
	symbolTable = ast->getST();
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

// TODO
string CFG::create_new_tempvar(Type t) {
	return "";
}

int CFG::get_var_index(string name) {
	return symbolTable.find(name)->second.second;
}

int CFG::get_var_type(string name) {
	return symbolTable.find(name)->second.first;
}
