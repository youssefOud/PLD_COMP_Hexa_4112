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



