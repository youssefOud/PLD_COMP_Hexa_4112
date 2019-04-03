#include "Appel.h"
#include <iostream>

using namespace std;

Appel::Appel(string nomFct) {
	id = nomFct;
}

Appel::Appel(string nomFct, list<Instruction*> l) {
	id = nomFct;
	for (list<Instruction*>::iterator it = l.begin(); it != l.end(); it++) {
		parametres.push_back(*it);	
	}
}

Appel::~Appel() {
	for (list<Instruction*>::iterator it = parametres.begin(); it != parametres.end(); it++) {
		delete *it;	
	}
}

string Appel::getId(){
	return id;
}

list<Instruction*> Appel::getExpressions() {
	return parametres;
}

void Appel::setId(string nomFct) {
	id = nomFct;
}

void Appel::setInstructions (list<Instruction*> e) {
	parametres=e;
}

void Appel::addInstruction(Instruction* e) {
	parametres.push_back(e);
}


string Appel::toString() {
	string print;
    	print += " Appel de la fct "+id;
    	print += " \r\n List<Expression*> \r\n ";
	for (list<Instruction*>::iterator it = parametres.begin(); it != parametres.end(); it++) {
		print += (*it)->toString()+"\r\n";	
	}

    	print += "\r\n";
	return print;
}

string Appel::buildIR(CFG *cfg) {
	string dest = cfg->create_new_tempvar(cfg->getPrototypeType(id));
	vector<string> params;
	params.push_back(dest);
	params.push_back(id);
	for (list<Instruction*>::iterator it = parametres.begin(); it != parametres.end(); it++) {
		string param = (*it)->buildIR(cfg);
		params.push_back(param);
	}
	cfg->addInstruction(IRInstr::Operation::call, params);
	return dest; 
};



