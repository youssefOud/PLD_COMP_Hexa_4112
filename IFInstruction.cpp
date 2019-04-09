#include "IFInstruction.h"
#include "BasicBlock.h"

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
	cfg->incrementNbIf();
	string varTest = clause->buildIR(cfg);

	BasicBlock *clauseBB = cfg->current_bb;
	clauseBB->varTest = varTest;
	
	BasicBlock *thenBB = new BasicBlock(cfg, ".trueCode_"+to_string(cfg->getNbIf()));//Rajouter les numeros
	//cfg->current_bb = thenBB;
	//for(list<Instruction*>::iterator it = this->blocIf.begin(); it != this->blocIf.end(); it++){
		//(*it)->buildIR(cfg);
	//}
	cfg->add_bb(thenBB);

	BasicBlock *elseBB = new BasicBlock(cfg, ".falseCode_"+to_string(cfg->getNbIf()));//Rajouter les numéros
	//cfg->current_bb = elseBB;
	//for(list<Instruction*>::iterator it = this->blocElse.begin(); it != this->blocElse.end(); it++){
		//(*it)->buildIR(cfg);
	//}
	cfg->add_bb(elseBB);
	
	
	BasicBlock *afterIfBB = new BasicBlock(cfg, ".afterIfBB_"+to_string(cfg->getNbIf()));//Rajouter les numéros
	cfg->current_bb = afterIfBB;
	cfg->add_bb(afterIfBB);
	afterIfBB->exit_true = clauseBB->exit_true;
	afterIfBB->exit_false = clauseBB->exit_false;

	clauseBB->exit_true = thenBB;
	clauseBB->exit_false = elseBB;

	thenBB->exit_true = afterIfBB;
	thenBB->exit_false = nullptr;
	elseBB->exit_true = afterIfBB;
	elseBB->exit_false = nullptr;
	//cfg->current_bb = afterIfBB;

	cfg->current_bb = thenBB;
	for(list<Instruction*>::iterator it = this->blocIf.begin(); it != this->blocIf.end(); it++){
		(*it)->buildIR(cfg);
	}

	cfg->current_bb = elseBB;
	for(list<Instruction*>::iterator it = this->blocElse.begin(); it != this->blocElse.end(); it++){
		(*it)->buildIR(cfg);
	}

	cfg->current_bb = afterIfBB;
	
	return "";
}
