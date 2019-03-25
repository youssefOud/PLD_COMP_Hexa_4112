#include "ExprSimple.h"

using namespace std;

string ExprSimple::genererCodeAssembleur(map<string, pair<int, int>> *st){
	return "";
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
