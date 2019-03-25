#include "ExprSimple.h"

using namespace std;

int ExprSimple::genererCodeAssembleur(map<string, pair<int, int>> *st, string *codeAss){
	if(!right->getId().empty()){ //l'rightession simple est un id
		return st->find(right->getId())->second.second;
	}
	else{
		st->insert( make_pair("temp"+to_string(nextFree), make_pair(1, nextFree) )); //1 correspond au type int dans enumeration
		*codeAss+= "movq $" + to_string(right->getNbr()) + ", " + to_string(nextFree) + "(%rbp)\r\n";
		nextFree-=8;
		return nextFree+8; 
	}
}

string ExprSimple::toString (){
	return "Right Value " + right->toString();
}

int ExprSimple::eval(){
	return right->getNbr();
}

void ExprSimple::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings){
	map<string,vector<int>>::iterator it2;
	if(right->getId() != "")//c'est une variable
			{
				it2 = staticAnalysis.find(right->getId());
				if (it2 != staticAnalysis.end()) {
					//on vérifie qu'elle a bien été initialisée
					if((*it2).second[0]==1){
						//on met à jour la ligne de la variable en disant qu'elle est utilisée
						(*it2).second[1]=1;
						
					}
					else{
						warnings.push_back("Variable utilisee mais non initialisee " +right->getId());
					}
				}
				else {
					//a gerer var droite utilisée mais non déclarée
					errors.push_back("Variable utilisee mais non declaree " + right->getId());
				}
			}
	
}
