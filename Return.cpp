#include "Return.h"
#include <string>
#include <vector>

Return::~Return()
{

}

Expression *Return::getExpr() {
    return expr;
}

string Return::genererCodeAssembleur(map<string, pair<Type, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " +to_string(offset)+ "(%rbp), %rax\r\n";
	return codeAss;
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
