#include "IFInstruction.h"

using namespace std;

IFInstruction::IFInstruction(Instruction* c, list<Instruction*> lif, list<Instruction*> lelse) {
	clause=c;
	list<Instruction*>::iterator it;  
	for (it = lif.begin(); it != lif.end(); it++) {
		blocIf.push_back(*it);	
	}

	for (it = lelse.begin(); it != lelse.end(); it++) {
		blocElse.push_back(*it);	
	}	
}

IFInstruction::~IFInstruction(){
	list<Instruction*>::iterator it;  
	for (it = blocIf.begin(); it != blocIf.end(); it++) {
		delete *it;	
	}

	for (it = blocElse.begin(); it != blocElse.end(); it++) {
		delete *it;	
	}	

}

Instruction * IFInstruction::getClause() {
	return clause;
}

list<Instruction*>* IFInstruction::getBlocIf() {
	return &blocIf;
}

list<Instruction*>* IFInstruction::getBlocElse() {
	return &blocElse;
}

void IFInstruction::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings) {

}

string IFInstruction::toString (){
	string print ="";
	//TODO
	print += " IF clause: " + clause->toString()+"\n Instructions IF: \n";

	list<Instruction*>::iterator it;  
	for (it = blocIf.begin(); it != blocIf.end(); it++) {
		print += (*it)->toString() + "\n";
	}
	print += " Instructions ELSE: \n ";
	for (it = blocElse.begin(); it != blocElse.end(); it++) {
		print += (*it)->toString() + "\n";	
	}	
	return print;	
}

string IFInstruction::buildIR(CFG *cfg){
	//TODO
	return "";
}
