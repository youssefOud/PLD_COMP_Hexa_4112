#include "Definition.h"
#include <string>


std::string Definition::toString() 
{
    return "Definition Expression "+expr->toString()+" LeftValue "+left->toString()+ " Type "+to_string(type)+"\n";
}


int Definition::getClassName(){
	return 2;
}

string Definition::genererCodeAssembleur(map<string, pair<int, int>> *st){
	/*if(!right->getId().empty()){
		string res = "movl " + to_string((st->find(right->getId()))->second.second) + "(%rbp), %eax\r\n";
		res += "movl %eax, " +to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";
		return res;
		//movl	-4(%rbp), %eax
		//movl	%eax, -8(%rbp)
	}
	else{
		return "movl $" +to_string(right->getNbr())+ ", " + to_string((st->find(left->getId()))->second.second)+ "(%rbp)\r\n";		
	}
	*/
	return "";	
}
