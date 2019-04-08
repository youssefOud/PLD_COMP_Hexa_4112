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
			string offsetVar = getMemoryOffset(params[0]);
			o << "movq $" << params[1] << ", " << offsetVar << "\r\n";
			break;
		}
		case (add) : {
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "addq " << offset2 << ", %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (sub) : {
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "subq " << offset2 << ", %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (mul) : {
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "imulq " << offset2 << ", %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (rmem) :
			break;
		case (wmem) : {
			string offset = getMemoryOffset(params[1]);
			if (!params[0].compare("!rax")) {
				o << "movq " << offset << ", %rax\r\n";
			} else {
				string offsetParams0 = getMemoryOffset(params[0]);
				o << "movq " << offset << ", %rax\r\n";	
				o << "movq %rax, " << offsetParams0 << "\r\n";
			}
			break;
		}
		case (call) :{
			if(!params[1].compare("putchar")){
				string offsetParam = getMemoryOffset(params[2]);
				string offsetDest = getMemoryOffset(params[0]);
				o << "movq " << offsetParam << ", %rdi\r\n";
				o << "call putchar\r\n";
				o << "movq %rax, " << offsetDest << "\r\n";
			}
			else{
				for (int i=2; i<params.size(); i++) {
					string offsetParam = getMemoryOffset(params[i]);
					switch(i) {
						case 2: {
							o << "movq " << offsetParam << ", %rdi\r\n";
							break;
						}
						case 3: {
							o << "movq " << offsetParam << ", %rsi\r\n";
							break;
						}
						case 4: {
							o << "movq " << offsetParam << ", %rdx\r\n";
							break;
						}
						case 5: {
							o << "movq " << offsetParam << ", %rcx\r\n";
							break;						
						}
						case 6: {
							o << "movq " << offsetParam << ", %r8\r\n";
							break;						
						}
						case 7: {
							o << "movq " << offsetParam << ", %r9\r\n";	
							break;
						}
						default:
							cerr << "Trop de paramètres dans la fonction, non géré actuellement" << endl;
							break;	
					}				
				}
				
				string offsetDest = getMemoryOffset(params[0]);
				
				o << "call " << params[1] << "\r\n";
				o << "movq %rax, " << offsetDest << "\r\n";
			}
			break;
		}
		case (cmp_eq) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "sete	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (cmp_mt) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "setg	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
			break;
		}
		case (cmp_me) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "setge	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (cmp_diff) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "setne	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (cmp_lt) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "setl	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (cmp_le) :{
			string offset1 = getMemoryOffset(params[1]);
			string offset2 = getMemoryOffset(params[2]);
			string offset3 = getMemoryOffset(params[0]);

			o << "movq " << offset1 << ", %rax\r\n";
			o << "cmpq " << offset2 << ", %rax\r\n";
			o << "setle	%al\r\n";
			o << "movzbq	%al, %rax\r\n";
			o << "movq %rax, " << offset3 << "\r\n";
			break;
		}
		case (neg) :{
			string offsetExprNeg = getMemoryOffset(params[0]);
			string offsetExpr = getMemoryOffset(params[1]);
			o << "movq " << offsetExpr << ", %rax\r\n";
			o << "negq %rax\r\n";
			o << "movq %rax, " << offsetExprNeg << "\r\n";
			break;
		}
		default: {
			break;
		}
	}
}

string IRInstr::getMemoryOffset(string param) {
	int memoryCase = bb->cfg->getOffsetFromSymbolTable(param);
	switch (memoryCase) {
		case 0:
			cerr << "N'existe pas dans la symbolTable" << endl;
			break;
		case 1:	
			return "%rdi";
		case 2:
			return "%rsi";
		case 3:
			return "%rdx";
		case 4:
			return "%rcx";
		case 5:
			return "%r8";
		case 6:
			return "%r9";
		default:
			return to_string(memoryCase) + "(%rbp)"; // Cas ou c'est un offset negatif généré par nous même
	}
	return 0;
}
