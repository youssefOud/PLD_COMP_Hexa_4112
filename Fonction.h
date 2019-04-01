#pragma once
#include <string.h>
#include <map>
#include <list>
#include <vector>
#include "Enum.h"

using namespace std;

extern int nextFree;

class Instruction;

class Fonction{

	public:
		Fonction();
		Fonction(string, string, list<Instruction*> instructions);
		~Fonction();
		
		string getId();
		list<Instruction*> getInstructions();
		Type getType();
		void setId(string id);
		void setInstructions (list<Instruction*> instructions);
		void addInstruction(Instruction* instr);
		Type convertTypeToInt(string nom); 
		string toString();
		void generateST();
		string genererCodeAssembleur();
		void generateSA();
		void processSA();
		void displaySymbolTable();
		void displayStaticAnalysis();
		void displayWarnings();
		void displayErrors();
		map<string,pair<Type, int>> *getST();

	private:
		string id;
		list <Instruction*> instructions;
		map<string,pair<Type, int>> symbolTable;
		Type type;
		map<string,vector<int>> staticAnalysis;
		list<string> errors;
		list<string> warnings;
};
