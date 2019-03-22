#include "Return.h"
#include <string>

Return::~Return()
{

}

Expression *Return::getExpr() {
    return expr;
}

string Return::genererCodeAssembleur(map<string, pair<int, int>> *st){
	/*if(!rightValue->getId().empty()){
	/*if(!rightValue->getId().empty()){
		//int res = (st)->find(expression.getId())->;
		//return "mov     eax, 42\r\n";
		return "movl " +to_string((st->find(rightValue->getId()))->second.second)+ "(%rbp), %eax\r\n";
		//movl	-4(%rbp), %eax
		return "";
	}
	else{
		return "movl $"+to_string(rightValue->getNbr())+", %eax\r\n";
	}*/
	return "";
}
