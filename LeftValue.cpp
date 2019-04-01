#include "LeftValue.h"


string LeftValue::buildIR(CFG *cfg) { 
	string var = cfg->create_new_tempvar(Type::INT); //1 pour type int
	int offset = cfg->getOffsetFromSymbolTable(id);
	vector<string> params1; //params de la premiere instruction
	vector<string> params2; //params de la deuxieme instruction

	params1.push_back(var);
	params1.push_back(to_string(offset));
	cfg->addInstruction(IRInstr::Operation::ldconst, params1);

	params2.push_back(var);
	params2.push_back("!bp");
	params2.push_back(var);

	cfg->addInstruction(IRInstr::Operation::add,params2);

	return var;
}


