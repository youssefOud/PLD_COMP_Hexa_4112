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
#include <iostream>
#include <utility>

using namespace std;

int nextFree = -8;


Fonction::Fonction(string nomFct, string typeFct, list<Instruction*> instr, DefAppel * da) {
	id = nomFct;
	type = convertTypeToInt(typeFct);
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

Type Fonction::convertTypeToInt(string nom) {
	Type t = VIDE;
	if (nom == "") t = VIDE;
	else if (nom == "int") t = INT;
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
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
		if((*it)->getClassName() == 1){  //Declaration
			map<string,pair<Type,int>>::iterator it2;
			it2 = this->symbolTable.find(((Declaration*)(*it))->getId());
			if (it2 != symbolTable.end()) {	
				// Existe deja dans la table des symboles : gérer cas d'erreur
				//déclarations multiples
				errors.push_back("Declarations multiples de la variable "+ ((Declaration*)(*it))->getId());
			} else {
				// On commence les adresses à -8
				pair<Type, int> temp;
				
				this->symbolTable.insert(make_pair(((Declaration*)(*it))->getId(), make_pair(((Declaration*)(*it))->getType(),nextFree)));
				nextFree-=8;
			}
		}
		
		else if((*it)->getClassName() == 2){ //Définition (Type d'affectation)
			map<string,pair<Type,int>>::iterator it2;
			it2 = this->symbolTable.find(((Definition*)(*it))->getLeft()->getId());
			if (it2 != symbolTable.end()) {	
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
	bool retFound=false;
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
		if((*it)->getClassName() == 1){  //Declaration
			map<string,vector<int>>::iterator it2;
			it2 = this->staticAnalysis.find(((Declaration*)(*it))->getId());
			if (it2 == staticAnalysis.end()) {	
				//déclaration d'une nouvelle variable
				vector<int> flags(2, 0);
				this->staticAnalysis.insert(make_pair(((Declaration*)(*it))->getId(),flags ));
				//ATTENTION LES DECLARATIONS MULTIPLES SONT GEREES DU COTE DE LA ST
			}
		}
		else if((*it)->getClassName() == 2){ //Définition (Type d'affectation)
			map<string,vector<int>>::iterator it2;
			((Definition*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings,prototypes,1);
			// traitement de la left value quel que soit le retour de la partie droite
			it2 = this->staticAnalysis.find(((Definition*)(*it))->getLeft()->getId());
			if (it2 == staticAnalysis.end()) {// elle n'a jamais été déclarée
				//on notifie qu'elle a été déclarée et initialisée
				vector<int> flags{1,0};
				this->staticAnalysis.insert(make_pair(((Definition*)(*it))->getLeft()->getId(),flags ));
			}
			//ATTENTION LES DECLARATIONS MULTIPLES SONT GEREES PAR LA ST	
		}
		else if( (*it)->getClassName() == 3  ){ //Affectation Simple (Type d'affectation)
			((AffectationSimple*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings,prototypes,1);
			map<string,vector<int>>::iterator it2;
			// traitement de la left value
			it2 = this->staticAnalysis.find(((AffectationSimple*)(*it))->getLeft()->getId());
			if (it2 != staticAnalysis.end()) {// elle a déjà été déclarée
				//on notifie qu'elle a été initialisée ou affectée et utilisée
				(*it2).second[0]=1;
			  	(*it2).second[1]=1;
			}
			else{
			//var gauche utilisée mais non déclarée
				errors.push_back("Variable utilisee mais non declaree " + ((AffectationSimple*)(*it))->getLeft()->getId());
			}	
		}
		else if( (*it)->getClassName() == 4  ){ //Return
			((Return*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings,prototypes,0);
			retFound=true;			
		}
		else if( (*it)->getClassName() == 5 ){
			((ExprMoins*)(*it))->getExpr1()->analyse(staticAnalysis,errors,warnings,prototypes,0);
			((ExprMoins*)(*it))->getExpr2()->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		else if( (*it)->getClassName() == 6 ){
			((ExprPlus*)(*it))->getExpr1()->analyse(staticAnalysis,errors,warnings,prototypes,0);
			((ExprPlus*)(*it))->getExpr2()->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		else if( (*it)->getClassName() == 7 ){
			((ExprMult*)(*it))->getExpr1()->analyse(staticAnalysis,errors,warnings,prototypes,0);
			((ExprMult*)(*it))->getExpr2()->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		else if( (*it)->getClassName() == 8 ){
			((ExprNeg*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		else if( (*it)->getClassName() == 9 ){
			((ExprSimple*)(*it))->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		else if( (*it)->getClassName() == 10 ){
			((Appel*)(*it))->analyse(staticAnalysis,errors,warnings,prototypes,0);
		}
		
	}
	if(type==0 && retFound){
		warnings.push_back("Fonction "+id+" de type void avec retour"  );
	}
	else if(type!=0 && !retFound){
		warnings.push_back("Retour attendu pour la fonction "+id+" ");
	}

}
	
	
	void Fonction::processSA(){

		for(map<string,vector<int>>::iterator it=staticAnalysis.begin() ; it!=staticAnalysis.end() ; ++it)
		{
			if((*it).second[1]==0){
				warnings.push_back("Variable non utilisee " +(*it).first );
			}
		}
	}
	
	void Fonction::displaySymbolTable(){
		//cout << "SymbolTable : "<< endl;
		//cout << "ID TYPE ADD"<<endl;
		for(map<string,pair<Type,int>>::iterator it=symbolTable.begin() ; it!=symbolTable.end() ; ++it)
		{
			//cout<< (*it).first << " " <<(*it).second.first << "   " << (*it).second.second <<endl;
		}
	}
	
	void Fonction::displayStaticAnalysis(){
		//cout << "StaticAnalysisTable : "<< endl;
		//cout << "ID INIT UTI"<<endl;
		for(map<string,vector<int>>::iterator it=staticAnalysis.begin() ; it!=staticAnalysis.end() ; ++it)
		{
			//cout<< (*it).first << " " << (*it).second[0] << "   " << (*it).second[1] <<endl;
		}
	}
	
	void Fonction::displayWarnings(){
	  //cout << "StaticAnalysisTable : Display warnings"<< endl;
	  for(list<string>::iterator it=warnings.begin() ; it!=warnings.end() ; ++it)
	  {
	    cout<< "Warning : "<< (*it) <<endl;
	  }
	}
	
	void Fonction::displayErrors(){
	  //cout << "StaticAnalysisTable : Display errors"<< endl;
	  for(list<string>::iterator it=errors.begin() ; it!=errors.end() ; ++it)
	  {
	    cout<< "Error: "<<(*it) <<endl;
	  }
	}

	int Fonction::getNumberOfErrors(){
		return errors.size();
	}
