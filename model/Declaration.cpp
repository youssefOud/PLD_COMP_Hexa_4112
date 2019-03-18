#include "Declaration.h"

Declaration::Declaration(std::string nomVar, int varType)
{
    id = nomVar;
    type = varType;
}

Declaration::~Declaration()
{

}

void Declaration::setId(std::string nV)
{
    id = nV;
}
std::string Declaration::getId()
{
    return id;
}

void Declaration::setType(int t)
{
    type = t;
}

int Declaration::getType()
{
    return type;
}

std::string Declaration::stringifyType() {
  
    std::string print = "UNKNOWN";
    
    switch(this->type) {
      case INT :
        print = "INT";
        break;
      case VIDE :
        print = "VOID";
        break;
    }
  
    return print;
}

std::string Declaration::toSmallString() 
{
    std::string print;
    print += id;
    print += " ("+stringifyType()+")";
    return print;
}

std::string Declaration::toString() 
{
    std::string print;
    print += "[I] Declaration || "+id;
    print += " ("+stringifyType()+")";
    print += "\r\n";
    
    return print;
}

