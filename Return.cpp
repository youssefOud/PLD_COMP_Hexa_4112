#include "Return.h"
#include <string>

Return::~Return()
{

}

RightValue *Return::getRightValue() {
    return rightValue;
}

string Return::genererCodeAssembleur(map<string, pair<int, int>> *st){
	if(!expression->getId().empty()){
		//int res = (st)->find(expression.getId())->;
		//return "mov     eax, 42\r\n";
		return "movl " +to_string((st->find(expression->getId()))->second.second)+ "(%rbp), %eax\r\n";
		//movl	-4(%rbp), %eax
		return "";
	}
	else{
		return "movl $"+to_string(expression->getNbr())+", %eax\r\n";
	}
}
