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
			cout << "Generation code assembleur : ldconst" << endl;
			// récuperer offset du premier argument et le mettre après le -
			int offsetVar = bb->cfg->getOffsetFromSymbolTable(params[0]);
			o << "movq $" << params[1] << ", " << to_string(offsetVar) << "(%rbp)\r\n";
			cout << "Fin Generation code assembleur : ldconst" << endl;
			break;
		}
		case (add) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "addq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (sub) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "subq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (mul) : {
			int offset1 = bb->cfg->getOffsetFromSymbolTable(params[1]);
			int offset2 = bb->cfg->getOffsetFromSymbolTable(params[2]);
			int offset3 = bb->cfg->getOffsetFromSymbolTable(params[0]);

			o << "movq " << to_string(offset1) << "(%rbp), %rax\r\n";
			o << "imulq " << to_string(offset2) << "(%rbp), %rax\r\n";
			o << "movq %rax, " << to_string(offset3) << "(%rbp)\r\n";
			break;
		}
		case (rmem) :
			break;
		case (wmem) : {
			cout << "Generation code assembleur : wmem" << endl;
			cout << params[0] << endl;
			cout << params[1] << endl;
			int offset = bb->cfg->getOffsetFromSymbolTable(params[1]);
			if (!params[0].compare("!rax")) {
				o << "movq " << to_string(offset) << "(%rbp), %rax\r\n";
			} else {
				int offsetParams0 = bb->cfg->getOffsetFromSymbolTable(params[0]);
				o << "movq " << to_string(offset) << "(%rbp), %rax\r\n";	
				o << "movq %rax, " << to_string(offsetParams0) << "(%rbp)\r\n";
			}
			cout << "Fin Generation code assembleur : wmem" << endl;
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
