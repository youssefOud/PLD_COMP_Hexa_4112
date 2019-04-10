#include "Affectation.h"

Affectation::Affectation(Instruction *e, LeftValue *l, string t)
{
    expr=e;
    left=l;
    type=convertTypeToInt(t);
}

Affectation::~Affectation()
{

}

Instruction *Affectation::getExpr()
{
    return expr;
}

LeftValue *Affectation::getLeft()
{
    return left;
}

Type Affectation::getType()
{
    return type;
}

void Affectation::setType(Type t)
{
    type = t;
}

Type Affectation::convertTypeToInt(string nom)
{
    Type t = Type::VIDE;
    if (nom == "") t = Type::VIDE;
    else if (nom == "int") t = Type::INT;
    return t;
}

bool Affectation::estCst(list<string> & opti)
{
    if(expr->getClassName() != 9)  //Si ce n'est pas une expression simple
    {
        return expr->estCst(opti);
    }
    return false; // Si c'est une expression simple, aucune optimisation n'est possible

}

