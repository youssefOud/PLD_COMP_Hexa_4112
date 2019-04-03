#include "CFG.h"
#include "BasicBlock.h"

CFG::CFG(Fonction* f, multimap<string,pair<Type,DefAppel *>> *protos) {
	ast = f;
	symbolTable = f->getST();
	nextFreeSymbolIndex = nextFree;
	prototypes = protos;
	current_bb = new BasicBlock(this, ".main");
	add_bb(current_bb);
	
}

void CFG::genererIR(){
	//for(list<Instruction*>::iterator it = ast->getInstructions().begin(); it != ast->getInstructions().end(); it++){
	//	(*it)->buildIR(this);
	//}
}

void CFG::add_bb(BasicBlock* bb) {
	bbs.push_back(bb);
}

void CFG::genererCodeAssembleur(ostream& o) {
	
	gen_asm_prologue(o);
	for(vector <BasicBlock*>::iterator it = this->bbs.begin(); it != this->bbs.end(); it++){
		(*it)->genererCodeAssembleur(o);	
	}
	gen_asm_epilogue(o);

	// Au minimum deux basics blocs dans chaque CFG car ils convergent tous sur un basic bloc qui sera celui du return ou si c'est un void vers une étiquette qui correspondra à l'épilogue
}

void CFG::gen_asm_prologue(ostream& o) {
	//calcule la taille nécessaire pour l'AR
	maxSizeAR = 8 * symbolTable->size();
	if(maxSizeAR % 16 !=0){
		maxSizeAR += 8;
	}

	o << ast->getId() << ": \r\n";
	o << "# prologue \r\n";
	o << "pushq %rbp # save %rbp on the stack \r\n";
	o << "movq %rsp, %rbp # define %rbp for the current function \r\n";
	o << "subq $" << to_string(maxSizeAR) << ", %rsp\r\n";
	o << "\r\n";
	o << "# body \r\n";
}

void CFG::gen_asm_epilogue(ostream& o) {
	o << "# epilogue \r\n";
	o << "leave # restore %rbp from the stack \r\n";
	o << "ret # return to the caller (here the shell) \r\n";
	o << "\r\n";
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
	current_bb->add_IRInstr(mnemo, symbolTable->find(params[0])->second.first, params);
}

int CFG::getNextFreeIndex() {
	return nextFreeSymbolIndex;
}

int CFG::getOffsetFromSymbolTable(string id){
	map<string,pair<Type, int>>::iterator  it= symbolTable->find(id);
    	if( it != symbolTable->end() ){
		return symbolTable->find(id)->second.second;
	}
	else {
		return 0; //0 signifie que aucune variable de ce nom n'a été trouvée
	}
}

Type CFG::getPrototypeType(string label){
	return prototypes->find(label)->second.first;
}
