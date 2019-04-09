#include "WhileInstruction.h"
#include "BasicBlock.h"

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
	cfg->incrementNbWhile();
	string varTest = clause->buildIR(cfg);
	
	BasicBlock *beforeWhileBB = cfg->current_bb;
	BasicBlock *clauseBB = new BasicBlock(cfg, ".clauseWhile_"+to_string(cfg->getNbWhile()));//Rajouter les numeros;
	clauseBB->varTest = varTest;
	cfg->add_bb(clauseBB);
	
	BasicBlock *doBB = new BasicBlock(cfg, ".doCode_"+to_string(cfg->getNbWhile()));//Rajouter les numeros
	//cfg->current_bb = doBB;
	//for(list<Instruction*>::iterator it = this->blocWhile.begin(); it != this->blocWhile.end(); it++){
		//(*it)->buildIR(cfg);
	//}
	cfg->add_bb(doBB);
	
	
	BasicBlock *afterWhileBB = new BasicBlock(cfg, ".afterWhileBB_"+to_string(cfg->getNbWhile()));//Rajouter les numéros
	cfg->current_bb = afterWhileBB;
	cfg->add_bb(afterWhileBB);
	afterWhileBB->exit_true = beforeWhileBB->exit_true;
	afterWhileBB->exit_false = beforeWhileBB->exit_false;

	clauseBB->exit_true = doBB;
	clauseBB->exit_false = afterWhileBB;

	doBB->exit_true = clauseBB;
	doBB->exit_false = nullptr;

	beforeWhileBB->exit_true = clauseBB;

	cfg->current_bb = doBB;
	for(list<Instruction*>::iterator it = this->blocWhile.begin(); it != this->blocWhile.end(); it++){
		(*it)->buildIR(cfg);
	}

	
	cfg->current_bb = afterWhileBB;
	return "";
}
