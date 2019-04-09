#include "WhileInstruction.h"
#include "Declaration.h"


using namespace std;

WhileInstruction::WhileInstruction(Instruction* c, list<Instruction*> l) {
	clause=c;
	list<Instruction*>::iterator it;  
	for (it = l.begin(); it != l.end(); it++) {
		blocWhile.push_back(*it);	
	}
}

WhileInstruction::~WhileInstruction(){
	list<Instruction*>::iterator it;  
	for (it = blocWhile.begin(); it != blocWhile.end(); it++) {
		delete *it;	
	}	

}

Instruction * WhileInstruction::getClause() {
	return clause;
}

list<Instruction*>* WhileInstruction::getBlocWhile() {
	return &blocWhile;
}

void WhileInstruction::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType){

	//Traitement de la clause
	clause->analyse(staticAnalysis,errors,warnings,prototypes,1);

	//Traitement du bloc WHILE
	list<string> ids;
	for(list<Instruction*>::iterator it = this->blocWhile.begin(); it != this->blocWhile.end(); it++){
		int id =(*it)->getClassName(); 
		switch (id) {
			case 1: 
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,0);
				ids.push_back(((Declaration *)(*it))->getId());
				break;
			case 5:
			case 6: 
			case 7:
			case 8: 
			case 9:
			case 10: 
			case 11:
			case 12:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,0);
				break;
			case 2:
			case 3:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,1);
				break;
			case 4:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,0);
				break;	
		 }
	}
	//On analyse la map  et on supprime les variables déclarées dans le while de la TAS
	map<string,vector<int>>::iterator it;
	for(list<string>::iterator it2=ids.begin() ; it2!=ids.end() ; ++it2)
	{
		it = staticAnalysis.find(*it2);
		if((*it).second[1]==0 &&  (*it).second[0]==0){
			warnings.push_back("Variable non utilisee " +(*it).first );
		}
		else if((*it).second[1]==0 &&  (*it).second[0]==1){
			warnings.push_back("Variable definie non utilisee " +(*it).first );
		}
		staticAnalysis.erase(it);
	}

}

string WhileInstruction::toString (){
	string print ="";
	//TODO
	print += " WHILE clause: " + clause->toString()+"\n Instructions While: \n";

	list<Instruction*>::iterator it;  
	for (it = blocWhile.begin(); it != blocWhile.end(); it++) {
		print += (*it)->toString() + "\n";
	}
	return print;
}

string WhileInstruction::buildIR(CFG *cfg){
	//TODO
	return "";
}

bool WhileInstruction::estCst(list<string> & opti){
	if(clause->estCst(opti)){
		opti.push_back("Optimisation possible au niveau de la ligne "+ to_string(clause->getNbLine()));	
	}
	for(list<Instruction*>::iterator it = this->blocWhile.begin(); it != this->blocWhile.end(); it++){
		if((*it)->estCst(opti)){
			opti.push_back("Optimisation possible au niveau de la ligne "+ to_string((*it)->getNbLine()));
		}
	}
	return false;
}


