#include "ExprNeg.h"

using namespace std;

string ExprNeg::toString ()
{
    return " de valeur "+to_string(eval())+"Expression "+expr->toString();
}

int ExprNeg::eval()
{
    return -(expr->eval());
}

void ExprNeg::analyse(map<string,vector<int>> & staticAnalysis,list<string> & errors,list<string> & warnings, multimap<string,pair<Type,DefAppel*>> & prototypes,bool returnType)
{
    expr->analyse(staticAnalysis,errors,warnings,prototypes,returnType);
}

string ExprNeg::buildIR(CFG *cfg)
{
    string var = expr->buildIR(cfg);
    string varNeg = cfg->create_new_tempvar(Type::INT);;
    vector<string> params;
    params.push_back(varNeg);
    params.push_back(var);
    cfg->addInstruction(IRInstr::Operation::neg, params);
    return varNeg;

}

bool ExprNeg::estCst(list<string> & opti)
{
    return expr->estCst(opti) ;
}
