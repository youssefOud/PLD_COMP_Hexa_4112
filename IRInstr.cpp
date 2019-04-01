#include "IRInstr.h"
#include "BasicBlock.h"

IRInstr::IRInstr(BasicBlock* bb_, Operation op_, Type t_, vector<string> params_) {
	bb = bb_; 
	op = op_;
	t = t_;
	params = params_;
}

void IRInstr::genererCodeAssembleur(ostream &o) {
	switch (op) {
		case (ldconst) :
			
			break;
		case (add) :
			break;
		case (sub) :
			break;
		case (mul) :
			break;
		case (rmem) :
			break;
		case (wmem) :
			break;
		case (call) :
			break;
		case (cmp_eq) :
			break;
		case (cmp_lt) :
			break;
		case (cmp_le) :
			break;
		default:
			break;
	}
}
