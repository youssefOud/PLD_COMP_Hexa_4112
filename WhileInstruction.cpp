#include "WhileInstruction.h"

using namespace std;

WhileInstruction::WhileInstruction(Instruction* c, list<Instruction*> l) {
	clause=c;
	list<Instruction*>::iterator it;  
	for (it = l.begin(); it != l.end(); it++) {
		blocWhile.push_back(*it);	
	}
}

WhileInstruction::~WhileInstruction(){
	list<Instruction*>::iterator it;  
	for (it = blocWhile.begin(); it != blocWhile.end(); it++) {
		delete *it;	
	}	

}

Instruction * WhileInstruction::getClause() {
	return clause;
}

list<Instruction*>* WhileInstruction::getBlocWhile() {
	return &blocWhile;
}

void WhileInstruction::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings) {

}

string WhileInstruction::toString (){
	string print ="";
	//TODO
	print += " WHILE clause: " + clause->toString()+"\n Instructions While: \n";

	list<Instruction*>::iterator it;  
	for (it = blocWhile.begin(); it != blocWhile.end(); it++) {
		print += (*it)->toString() + "\n";
	}
	return print;
}

string WhileInstruction::buildIR(CFG *cfg){
	//TODO
	return "";
}
