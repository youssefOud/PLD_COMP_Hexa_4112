#ifdef DEBUG_ENABLE
    #define debug(debugString) std::cout << (debugString) << std::endl;
#else
    #define debug(debugString)
#endif

#include "Fonction.h"
#include "Declaration.h"
#include "Definition.h"
#include "AffectationSimple.h"
#include "Return.h"
#include "ExprMoins.h"
#include "ExprPlus.h"
#include "ExprMult.h"
#include "ExprNeg.h"
#include "ExprSimple.h"
#include "Appel.h"
#include "IFInstruction.h"
#include "WhileInstruction.h"
#include <iostream>
#include <utility>

using namespace std;

int nextFree = -8;


Fonction::Fonction(string nomFct, string typeFct, list<Instruction*> instr, DefAppel * da) {
	id = nomFct;
	type = convertStringToType(typeFct);
	instructions = instr;
	defAppel = da;
}

Fonction::~Fonction() {
	for (list<Instruction*>::iterator it = instructions.begin(); it != instructions.end(); it++) {
		delete *it;	
	}
	delete defAppel;
}

string Fonction::getId(){
	return id;
}

DefAppel* Fonction::getDefAppel(){
	return defAppel;
}

list<Instruction*> * Fonction::getInstructions() {
	return &instructions;
}

Type Fonction::getType(){
	return type;
}

void Fonction::setId(string nomFct) {
	id = nomFct;
}

void Fonction::setInstructions (list<Instruction*> instr) {
	instructions=instr;
}

void Fonction::addInstruction(Instruction* instr) {
	instructions.push_back(instr);
}

map<string,pair<Type, int>> *Fonction::getST() {
	return &symbolTable;
}

Type Fonction::convertStringToType(string nom) {
	Type t = VIDE;
	if (nom == "") t = VIDE;
	else if (nom == "int") t = INT;
	else if (nom == "char") t = CHAR;
	return t; 
}

string Fonction::toString() {
	string print;
    print += " Fonction id "+id;
    print += " type ("+to_string(type)+") \r\n List<Instruction*> \r\n ";
	for (list<Instruction*>::iterator it = instructions.begin(); it != instructions.end(); it++) {
		print += (*it)->toString()+"\r\n";	
	}

    print += "\r\n";
	return print;
}


void Fonction::generateST(){
	int compteurParam = 1;
	for (unordered_multimap<string,string>::iterator itParam = defAppel->getParameters()->begin(); itParam != defAppel->getParameters()->end(); itParam++) {
		// 1er : nom ; 2eme : type
		Type t = convertStringToType((*itParam).second);
		this->symbolTable.insert(make_pair ( (*itParam).first, make_pair(t,compteurParam++) ) );
	}
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
		if((*it)->getClassName() == 1){  //Declaration
			map<string,pair<Type,int>>::iterator it2;
			it2 = this->symbolTable.find(((Declaration*)(*it))->getId());
			if (it2 != symbolTable.end()) {	
				// Existe deja dans la table des symboles : gérer cas d'erreur
				//déclarations multiples
				debug("Error : Declarations multiples de la variable "+ ((Declaration*)(*it))->getId());
				errors.push_back("Declarations multiples de la variable "+ ((Declaration*)(*it))->getId());
			} else {
				// On commence les adresses à -8
				this->symbolTable.insert(make_pair(((Declaration*)(*it))->getId(), make_pair(((Declaration*)(*it))->getType(),nextFree)));
				nextFree-=8;
			}
		}
		
		else if((*it)->getClassName() == 2){ //Définition (Type d'affectation)
			map<string,pair<Type,int>>::iterator it2;
			it2 = this->symbolTable.find(((Definition*)(*it))->getLeft()->getId());
			if (it2 != symbolTable.end()) {	
				debug("Error : Declarations multiples de la variable "+ ((Definition*)(*it))->getLeft()->getId());
				errors.push_back("Declarations multiples de la variable "+ ((Definition*)(*it))->getLeft()->getId());
			} else {
				// On commence les adresses à -8
				this->symbolTable.insert(make_pair(((Definition*)(*it))->getLeft()->getId(), make_pair(((Definition*)(*it))->getType(),nextFree)));
				nextFree-=8;
			}
		}
	}
}
void Fonction::generateSA(multimap<string,pair<Type,DefAppel*>> & prototypes){
	//Insertion des paramètres dans la table d'analyse statique 
	vector<int> flagsParam{1,0};
	for (unordered_multimap<string,string>::iterator itParam = defAppel->getParameters()->begin(); itParam != defAppel->getParameters()->end(); itParam++) {
		// 1er : nom ; 2eme : type
		Type t = convertStringToType((*itParam).second);
		this->staticAnalysis.insert(make_pair ( (*itParam).first, flagsParam) );
	}
	bool retFound=false;
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
		int id =(*it)->getClassName(); 
		switch (id) {
			case 1: 
			case 5:
			case 6: 
			case 7:
			case 8: 
			case 9:
			case 10: 
			case 11:
			case 13:
			case 12:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,0);
				break;
			case 2:
			case 3:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,1);
				break;
			case 4:
				(*it)->analyse(staticAnalysis,errors,warnings,prototypes,0);
				retFound=true;	
				break;	
		 }
		
	}
	if(type==0 && retFound){
		debug("Warning : Fonction "+id+" de type void avec retour")
		warnings.push_back("Fonction "+id+" de type void avec retour"  );
	}
	else if(type!=0 && !retFound){
		debug("Warning : Retour attendu pour la fonction "+id+" ");
		warnings.push_back("Retour attendu pour la fonction "+id+" ");
	}

}
	
	
	void Fonction::processSA(){
		for(map<string,vector<int>>::iterator it=staticAnalysis.begin() ; it!=staticAnalysis.end() ; ++it)
		{
			if((*it).second[1]==0 &&  (*it).second[0]==0){
				warnings.push_back("Variable non utilisee " +(*it).first );
			}
			else if((*it).second[1]==0 &&  (*it).second[0]==1){
				warnings.push_back("Variable definie non utilisee " +(*it).first );
			}
		}
	}
	
	void Fonction::displaySymbolTable(){
		cerr << "SymbolTable : "<< endl;
		cerr << "ID TYPE ADD"<<endl;
		for(map<string,pair<Type,int>>::iterator it=symbolTable.begin() ; it!=symbolTable.end() ; ++it)
		{
			cerr<< (*it).first << " " <<(*it).second.first << "   " << (*it).second.second <<endl;
		}
	}
	
	void Fonction::displayStaticAnalysis(){
		cerr << "StaticAnalysisTable : "<< endl;
		cerr << "ID INIT UTI"<<endl;
		for(map<string,vector<int>>::iterator it=staticAnalysis.begin() ; it!=staticAnalysis.end() ; ++it)
		{
			cerr<< (*it).first << " " << (*it).second[0] << "   " << (*it).second[1] <<endl;
		}
	}
	
	void Fonction::displayWarnings(){
	  cerr << "StaticAnalysisTable : Display warnings"<< endl;
	  for(list<string>::iterator it=warnings.begin() ; it!=warnings.end() ; ++it)
	  {
	    cout<< "Warning : "<< (*it) <<endl;
	  }
	}
	
	void Fonction::displayErrors(){
	  cerr << "StaticAnalysisTable : Display errors"<< endl;
	  for(list<string>::iterator it=errors.begin() ; it!=errors.end() ; ++it)
	  {
	    cout<< "Error : "<<(*it) <<endl;
	  }
	}
	
	void Fonction::displayOpti(){
	  cerr << "Optimisations : Display opti"<< endl;
	  for(list<string>::iterator it=opti.begin() ; it!=opti.end() ; ++it)
	  {
	    cout<< "Opti : "<< (*it) <<endl;
	  }
	}	
	
	int Fonction::getNumberOfErrors(){
		return errors.size();
	}

	void Fonction::optimize(){
		for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
			if((*it)->estCst(opti)){
				opti.push_back("Optimisation possible au niveau de la ligne "+ to_string((*it)->getNbLine()));
			}
		}
		
	}
