#include "Fonction.h"

Fonction::Fonction(string nomFct, string typeFct) {
	id = nomFct;
	type = convertTypeToInt(typeFct);
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
	instructions = instr;
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

