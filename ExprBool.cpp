#include "ExprBool.h"

using namespace std;

string ExprBool::toString (){
	return " Expr Bool de valeur "+to_string(eval())+" Expression 1 "+expr1->toString()+" Expression 2 "+expr2->toString()+ " Operateur "+ operateur ;
}

int ExprBool::eval(){
	if (operateur == "=="){
		if( (expr1->eval()-expr2->eval()) == 0 ){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (operateur == "<"){
		if( (expr1->eval()-expr2->eval()) < 0 ){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (operateur == "<="){
		if( (expr1->eval()-expr2->eval()) <= 0 ){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (operateur == ">="){
		if( (expr1->eval()-expr2->eval()) >= 0 ){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (operateur == ">"){
		if( (expr1->eval()-expr2->eval()) > 0 ){
			return 1;
		}
		else{
			return 0;
		}
	}else{
		if( (expr1->eval()-expr2->eval()) == 0 ){
			return 0;
		}
		else{
			return 1;
		}
	}
}

void ExprBool::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes, bool returnType) {
	expr1->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
	expr2->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
}

string ExprBool::buildIR(CFG *cfg){
	string var1 = expr1->buildIR(cfg);
	string var2 = expr2->buildIR(cfg);
	string var3 = cfg->create_new_tempvar(Type::INT); //1 pour type int
	vector<string> params;
	params.push_back(var3);
	params.push_back(var1);
	params.push_back(var2);
	if(operateur == "=="){
		cfg->addInstruction(IRInstr::Operation::cmp_eq, params);
	}else if (operateur == "<"){
		cfg->addInstruction(IRInstr::Operation::cmp_lt, params);
	}else if (operateur == "<="){
		cfg->addInstruction(IRInstr::Operation::cmp_le, params);
	}else if (operateur == ">="){
		cfg->addInstruction(IRInstr::Operation::cmp_me, params);
	}else if (operateur == ">"){
		cfg->addInstruction(IRInstr::Operation::cmp_mt, params);
	}else{
		cfg->addInstruction(IRInstr::Operation::cmp_diff, params);
	}
	return var3;
}

bool ExprBool::estCst(list<string> & opti) { 
return expr1->estCst(opti) && expr2->estCst(opti);
}
