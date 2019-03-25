#include "Return.h"
#include <string>

Return::~Return()
{

}

Expression *Return::getExpr() {
    return expr;
}

string Return::genererCodeAssembleur(map<string, pair<int, int>> *st){
	string codeAss = "";
	int offset = expr->genererCodeAssembleur(st , &codeAss);
	codeAss += "movq " +to_string(offset)+ "(%rbp), %rax\r\n";
	return codeAss;
}
