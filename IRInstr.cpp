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
		case (ldconst) : {
			// récuperer offset du premier argument et le mettre après le -
			int offsetVar = bb->cfg->getOffsetFromSymbolTable(params[0]);
			o << "movq $" << params[1] << ", " << to_string(offsetVar) << "(%rbp)\r\n";
			break;
		}
		case (add) :
			break;
		case (sub) :
			break;
		case (mul) :
			break;
		case (rmem) :
			break;
		case (wmem) : {
			if (!params[0].compare("!rax")) {
				o << "movq " << params[1] << "(%rbp), %rax\r\n";
			} 
			break;
		}
		case (call) :
			break;
		case (cmp_eq) :
			break;
		case (cmp_lt) :
			break;
		case (cmp_le) :
			break;
		default: {
			break;
		}
	}
}
