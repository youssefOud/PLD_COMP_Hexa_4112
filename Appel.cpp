#include "Appel.h"
#include <iostream>

using namespace std;

Appel::Appel(string nomFct) {
	id = nomFct;
}

Appel::Appel(string nomFct, list<Expression*> l) {
	id = nomFct;
	for (list<Expression*>::iterator it = l.begin(); it != l.end(); it++) {
		expressions.push_back(*it);	
	}
}

Appel::~Appel() {
	for (list<Expression*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		delete *it;	
	}
}

string Appel::getId(){
	return id;
}

list<Expression*> Appel::getExpressions() {
	return expressions;
}

void Appel::setId(string nomFct) {
	id = nomFct;
}

void Appel::setInstructions (list<Expression*> e) {
	expressions=e;
}

void Appel::addInstruction(Expression* e) {
	expressions.push_back(e);
}


string Appel::toString() {
	string print;
    	print += " Appel de la fct "+id;
    	print += " \r\n List<Expression*> \r\n ";
	for (list<Expression*>::iterator it = expressions.begin(); it != expressions.end(); it++) {
		print += (*it)->toString()+"\r\n";	
	}

    	print += "\r\n";
	return print;
}



