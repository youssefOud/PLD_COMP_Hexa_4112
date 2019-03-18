#include <string.h>
#include <map>
#include <list>
#include "Instruction.h"
#include "Enum.h"

using namespace std; 

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

	private:
		string id;
		list <Instruction*> instructions;
		map<string,int> dico;
		type_e type;
};
