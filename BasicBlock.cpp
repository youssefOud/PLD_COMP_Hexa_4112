#include "BasicBlock.h"

BasicBlock::BasicBlock(CFG* cfg_, string entry_label) {
	cfg = cfg_;
	label = entry_label;
	varTest = "";
	exit_true = nullptr;
	exit_false = nullptr;
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params) {
	IRInstr * newInstr = new IRInstr(this, op, t, params);
	instrs.push_back(newInstr);
}

void BasicBlock::genererCodeAssembleur(ostream &o) {
	o << label << ":\r\n";
	for(vector<IRInstr*>::iterator it = this->instrs.begin(); it != this->instrs.end(); it++){
		(*it)->genererCodeAssembleur(o);	
	}
	if(exit_true == nullptr && exit_false == nullptr){
		o << "jmp .epilogue\r\n\r\n";
	}
	else if (exit_true != nullptr && exit_false == nullptr){
		string jumpLabelTrue = exit_true->label;
		o << "jmp " << jumpLabelTrue << "\r\n\r\n";
	}
	else if (exit_true != nullptr && exit_false != nullptr){
		string jumpLabelTrue = exit_true->label;
		string jumpLabelFalse = exit_false->label;
		int offset = cfg->getOffsetFromSymbolTable(varTest);
		o << "movq " << to_string(offset) << "(%rbp), %rax\r\n";	
		o << "cmpq $0, %rax\r\n";

		o << "jne " << jumpLabelTrue << "\r\n";
		o << "jmp " << jumpLabelFalse << "\r\n\r\n";
	}
}
