#include "Fonction.h"
#include "Declaration.h"
#include "Definition.h"
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
	std::string print;
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
	for(std::list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){

		if((*it)->getClassName() == 1){  //Declaration
			std::map<string,pair<int,int>>::iterator it2;
			it2 = this->symbolTable.find(((Declaration*)(*it))->getId());
			if (it2 != symbolTable.end()) {	
				// Existe deja dans la table des symboles : gérer cas d'erreur
				cerr << "erreur" << endl;
			} else {
				// On commence les adresses à -8
				pair<int, int> temp;
				//temp
				adresseCount-=8;
				this->symbolTable.insert(make_pair(((Declaration*)(*it))->getId(), std::make_pair(((Declaration*)(*it))->getType(),adresseCount)));
				cout<< ((Declaration*)(*it))->getId() << "     " << ((Declaration*)(*it))->getType() << "      " << adresseCount <<endl ;
			}
		}
		
		if((*it)->getClassName() == 2){ //Définition (Type d'affectation)
			std::map<string,pair<int,int>>::iterator it2;
			it2 = this->symbolTable.find(((Definition*)(*it))->getLeft()->getId());
			if (it2 != symbolTable.end()) {	
				// Existe deja dans la table des symboles : gérer cas d'erreur
				cerr << "erreur" << endl;
			} else {
				// On commence les adresses à -8
				adresseCount-=8;
				this->symbolTable.insert(make_pair(((Definition*)(*it))->getLeft()->getId(), std::make_pair(((Definition*)(*it))->getType(),adresseCount)));
				cout<< ((Definition*)(*it))->getLeft()->getId() << "     " << ((Definition*)(*it))->getType() << "      " << adresseCount <<endl ;
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
	
	for(std::list<Instruction*>::iterator it = this->instructions.begin(); it != this->instructions.end(); it++){
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

