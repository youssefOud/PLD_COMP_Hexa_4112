#include "Declaration.h"

Declaration::Declaration(std::string nomVar, std::string varType)
{
    	id = nomVar;
	type = convertTypeToInt(varType);
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

void Declaration::setType(Type t)
{
    type = t;
}

Type Declaration::getType()
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
    print += " Declaration id "+id;
    print += " type ("+stringifyType()+")";
    print += "\r\n";
    
    return print;
}

Type Declaration::convertTypeToInt(string nom) {
	Type t = Type::VIDE;
	if (nom == "") t = Type::VIDE;
	else if (nom == "int") t = Type::INT;
	return t; 
}

int Declaration::getClassName(){
	return 1;
}

string Declaration::genererCodeAssembleur(map<string, pair<Type, int>> *st){
	return "";
}
