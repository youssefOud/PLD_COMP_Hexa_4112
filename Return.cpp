#include "Return.h"
#include <string>
#include <vector>

Return::~Return()
{

}

Instruction *Return::getExpr() {
    return expr;
}

string Return::buildIR(CFG *cfg){
	//TODO
	string r = expr->buildIR(cfg);
	vector<string> params;
	params.push_back("!rax");
	params.push_back(r);
	cfg->addInstruction( IRInstr::Operation::wmem, params);
	return r;
}
