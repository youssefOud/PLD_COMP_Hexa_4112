#include "Fonction.h"
#include "Declaration.h"
#include "Definition.h"
#include "AffectationSimple.h"
#include "Return.h"
#include <iostream>
#include <utility>

using namespace std;
Fonction::Fonction(string nomFct, string typeFct, list<Instruction*> instr) {
	id = nomFct;
	type = convertTypeToInt(typeFct);
	instructions=instr;
}

Fonction::~Fonction() {
	for (list<Instruction*>::iterator it = instructions.begin(); it != instructions.end(); it++) {
		delete *it;	
	}
	//delete instructions;
}

string Fonction::getId(){
	return id;
}

list<Instruction*> Fonction::getInstructions() {
	return instructions;
}

type_e Fonction::getType(){
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

type_e Fonction::convertTypeToInt(string nom) {
	type_e t = VIDE;
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
	int adresseCount = 0;
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){

		if((*it)->getClassName() == 1){  //Declaration
			map<string,pair<int,int>>::iterator it2;
			it2 = this->symbolTable.find(((Declaration*)(*it))->getId());
			if (it2 != symbolTable.end()) {	
				// Existe deja dans la table des symboles : gérer cas d'erreur
				//déclarations multiples
				errors.push_back("Declarations multiples de la variable "+ ((Declaration*)(*it))->getId());
			} else {
				// On commence les adresses à -8
				pair<int, int> temp;
				//temp
				adresseCount-=8;
				this->symbolTable.insert(make_pair(((Declaration*)(*it))->getId(), make_pair(((Declaration*)(*it))->getType(),adresseCount)));
			}
		}
		
		else if((*it)->getClassName() == 2){ //Définition (Type d'affectation)
			map<string,pair<int,int>>::iterator it2;
			it2 = this->symbolTable.find(((Definition*)(*it))->getLeft()->getId());
			if (it2 != symbolTable.end()) {	
				errors.push_back("Declarations multiples de la variable "+ ((Definition*)(*it))->getLeft()->getId());
			} else {
				// On commence les adresses à -8
				adresseCount-=8;
				this->symbolTable.insert(make_pair(((Definition*)(*it))->getLeft()->getId(), make_pair(((Definition*)(*it))->getType(),adresseCount)));
			}
		}
	}
}


string Fonction::genererCodeAssembleur(){

	string assembleur = "";
	assembleur += ".text                       # section declaration\r\n";
	assembleur += ".global main                # entry point\r\n";
	assembleur += "\r\n";

	assembleur += "main: \r\n";
	assembleur += "# prologue \r\n";
	assembleur += "pushq %rbp # save %rbp on the stack \r\n";
	assembleur += "movq %rsp, %rbp # define %rbp for the current function \r\n";

	assembleur += "# body \r\n";
	
	for(list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
		// on ne fait rien quand c'est juste une déclaration
		//if ((*it)->getClassName() != 1) {
			assembleur+= (*it)->genererCodeAssembleur(&symbolTable);
		//}
	}
	
	assembleur += "# epilogue \r\n";
	assembleur += "popq %rbp # restore %rbp from the stack \r\n";
	assembleur += "ret # return to the caller (here the shell) \r\n";

	return assembleur;
}

void Fonction::generateSA(){
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
			((Definition*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings);
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
			((AffectationSimple*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings);
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
			((Return*)(*it))->getExpr()->analyse(staticAnalysis,errors,warnings);			
		}
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
		cout << "SymbolTable : "<< endl;
		cout << "ID TYPE ADD"<<endl;
		for(map<string,pair<int,int>>::iterator it=symbolTable.begin() ; it!=symbolTable.end() ; ++it)
		{
			cout<< (*it).first << " " <<(*it).second.first << "   " << (*it).second.second <<endl;
		}
	}
	
	void Fonction::displayStaticAnalysis(){
		cout << "StaticAnalysisTable : "<< endl;
		cout << "ID INIT UTI"<<endl;
		for(map<string,vector<int>>::iterator it=staticAnalysis.begin() ; it!=staticAnalysis.end() ; ++it)
		{
			cout<< (*it).first << " " << (*it).second[0] << "   " << (*it).second[1] <<endl;
		}
	}
	
	void Fonction::displayWarnings(){
	  cout << "StaticAnalysisTable : Display warnings"<< endl;
	  for(list<string>::iterator it=warnings.begin() ; it!=warnings.end() ; ++it)
	  {
	    cout<< (*it) <<endl;
	  }
	}
	
	void Fonction::displayErrors(){
	  cout << "StaticAnalysisTable : Display errors"<< endl;
	  for(list<string>::iterator it=errors.begin() ; it!=errors.end() ; ++it)
	  {
	    cout<< (*it) <<endl;
	  }
	}


