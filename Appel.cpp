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

void Appel::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes, bool returnType) {
	//On commence par vérifier que la fonction a déjà été définie
	bool hasBeenDefined=false;
	auto it = prototypes.begin();
	for(it =prototypes.begin() ; !hasBeenDefined && it!=prototypes.end() ; ++it){
			if(!it->first.compare(id)){
				hasBeenDefined=true;
			}
	}
	--it;
	//Si elle n'a pas été définie, on s'arrête
	if(!hasBeenDefined){
		warnings.push_back("Fonction "+ id +" utilisee mais non definie");
	}
	//Si elle a déjà été définie
	else{
		//On commence par vérifier la compatiblité entre le prototype et l'appel au niveau du nombre de paramètres (comme int et char sont compatibles, 
		//aucune vérification à faire au niveau des types
		int nbParam = expressions.size();
		int nbParamExpected = it->second.second->getParameters().size();
		if( nbParam == nbParamExpected ){ // Si on a le bon nombre de paramètres

			//On vérifie chaque expression passée en paramètre
			for (list<Instruction*>::iterator instr = expressions.begin(); instr != expressions.end(); instr++) {
				
				(*instr)->analyse( staticAnalysis, errors, warnings,prototypes,returnType);	
			}
		} 
		else{
			if(nbParam > nbParamExpected){
				warnings.push_back("Trop d'arguments pour la fonction "+ id +" !");
			}
			else{
				warnings.push_back("Pas assez d'arguments pour la fonction "+ id +" !");
			}
		}

		//S'il s'agit d'un appel de fonction faisant partie d'une affectation, on vérifie le type de retour

		if( returnType && it->second.first == 0){
			warnings.push_back("La fonction "+ id +" a un retour void !");
		}
		
	}
}




