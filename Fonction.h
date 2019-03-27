#pragma once
#include <string.h>
#include <map>
#include <list>
#include <vector>
#include "Instruction.h"
#include "Enum.h"

using namespace std;

extern int nextFree;

class Fonction{

	public:
		Fonction();
		Fonction(string, string, list<Instruction*> instructions);
		~Fonction();
		
		string getId();
		list<Instruction*> getInstructions();
		type_e getType();
		void setId(string id);
		void setInstructions (list<Instruction*> instructions);
		void addInstruction(Instruction* instr);
		type_e convertTypeToInt(string nom); 
		string toString();
		void generateST();
		string genererCodeAssembleur();
		void generateSA();
		void processSA();
		void displaySymbolTable();
		void displayStaticAnalysis();
		void displayWarnings();
		void displayErrors();
		int getNumberOfErrors();

	private:
		string id;
		list <Instruction*> instructions;
		map<string,pair<int, int>> symbolTable;
		type_e type;
		map<string,vector<int>> staticAnalysis;
		list<string> errors;
		list<string> warnings;
};
