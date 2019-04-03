#include "Appel.h"
#include <iostream>

using namespace std;

Appel::Appel(string nomFct) {
	id = nomFct;
}

Appel::Appel(string nomFct, list<Instruction*> l) {
	id = nomFct;
	for (list<Instruction*>::iterator it = l.begin(); it != l.end(); it++) {
		expressions.push_back(*it);	
	}
}

Appel::~Appel() {
	for (list<Instruction*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		delete *it;	
	}
}

string Appel::getId(){
	return id;
}

list<Instruction*> Appel::getExpressions() {
	return expressions;
}

void Appel::setId(string nomFct) {
	id = nomFct;
}

void Appel::setInstructions (list<Instruction*> e) {
	expressions=e;
}

void Appel::addInstruction(Instruction* e) {
	expressions.push_back(e);
}


string Appel::toString() {
	string print;
    	print += " Appel de la fct "+id;
    	print += " \r\n List<Expression*> \r\n ";
	for (list<Instruction*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		print += (*it)->toString()+"\r\n";	
	}

    	print += "\r\n";
	return print;
}

void Appel::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & 	prototypes) {
	//On commence par vérifier que la fonction a déjà été définie
	bool hasBeenDefined=false;
	for(auto it=prototypes.begin() ; !hasBeenDefined && it!=prototypes.end() ; ++it){
			if(!it->first.compare(id)){
				hasBeenDefined=true;
			}
	}
	//Si elle n'a pas été définie, on s'arrête
	if(!hasBeenDefined){
		warnings.push_back("Fonction "+ id +" utilisee mais non definie");
	}
	//Si elle a déjà été définie
	else{
		//On 
		for (list<Instruction*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		analyse( staticAnalysis, errors, warnings,prototypes);	
		}
	}
	
}



