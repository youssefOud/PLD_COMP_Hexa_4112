#include "IFInstruction.h"
#include "Declaration.h"

using namespace std;

IFInstruction::IFInstruction(Instruction* c, list<Instruction*> lif, list<Instruction*> lelse) {
	clause=c;
	list<Instruction*>::iterator it;  
	for (it = lif.begin(); it != lif.end(); it++) {
		blocIf.push_back(*it);	
	}

	for (it = lelse.begin(); it != lelse.end(); it++) {
		blocElse.push_back(*it);	
	}	
}

IFInstruction::~IFInstruction(){
	list<Instruction*>::iterator it;  
	for (it = blocIf.begin(); it != blocIf.end(); it++) {
		delete *it;	
	}

	for (it = blocElse.begin(); it != blocElse.end(); it++) {
		delete *it;	
	}	

}

Instruction * IFInstruction::getClause() {
	return clause;
}

list<Instruction*>* IFInstruction::getBlocIf() {
	return &blocIf;
}

list<Instruction*>* IFInstruction::getBlocElse() {
	return &blocElse;
}

string IFInstruction::toString (){
	string print ="";
	//TODO
	print += " IF clause: " + clause->toString()+"\n Instructions IF: \n";

	list<Instruction*>::iterator it;  
	for (it = blocIf.begin(); it != blocIf.end(); it++) {
		print += (*it)->toString() + "\n";
	}
	print += " Instructions ELSE: \n ";
	for (it = blocElse.begin(); it != blocElse.end(); it++) {
		print += (*it)->toString() + "\n";	
	}	
	return print;	
}

string IFInstruction::buildIR(CFG *cfg){
	//TODO
	return "";
}

void IFInstruction::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType) {
	//Traitement de la clause
	clause->analyse(staticAnalysis,errors,warnings,prototypes,1);

	//Traitement du bloc IF
	list<string> ids;
	for(list<Instruction*>::iterator it = this->blocIf.begin(); it != this->blocIf.end(); it++){
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
	//On analyse la map  et on supprime les variables déclarées dans le if de la TAS
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

	//Traitement du bloc ELSE
	ids.clear();
	for(list<Instruction*>::iterator it = this->blocElse.begin(); it != this->blocElse.end(); it++){
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
	//On analyse la map  et on supprime les variables déclarées dans le else de la TAS
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

bool IFInstruction::estCst(list<string> & opti){
	if(clause->estCst(opti)){
		opti.push_back("Optimisation possible au niveau de l'instruction "+ clause->toString());	
	}
	for(list<Instruction*>::iterator it = this->blocIf.begin(); it != this->blocIf.end(); it++){
		if((*it)->estCst(opti)){
			opti.push_back("Optimisation possible au niveau de l'instruction "+ (*it)->toString());
		}
	}
	for(list<Instruction*>::iterator it = this->blocElse.begin(); it != this->blocElse.end(); it++){
		if((*it)->estCst(opti)){
			opti.push_back("Optimisation possible au niveau de l'instruction "+ (*it)->toString());
		}
	}
	return false;

}
