#include "AffectationSimple.h"



std::string AffectationSimple::toString() 
{
    return "AffectationSimple RightValue "+right->toString()+" LeftValue "+left->toString()+"\n";
}

int AffectationSimple::getClassName(){
	return 3;
}

string AffectationSimple::genererCodeAssembleur(map<string, pair<int, int>> *st){
	if(!right->getId().empty()){
		string res = "movl " + to_string((st->find(right->getId()))->second.second) + "(%rbp), %eax\r\n";
		res += "movl %eax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
		return res;
		//movl	-4(%rbp), %eax
		//movl	%eax, -8(%rbp)
	}
	else{
		return "movl $" +to_string(right->getNbr())+ ", " + to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
		//movl	$3, -4(%rbp)	
	}
}
