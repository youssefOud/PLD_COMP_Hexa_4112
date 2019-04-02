#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "calc.h"
using namespace antlr4;
using namespace std;
int main(int argc, const char ** argv) {
	
  bool a,c,o = false;
  for (int i = 1; i<argc ; i++) {
    string s(argv[i]);
    if (!s.compare("-a")) {
        a = true;
    }
    else if (!s.compare("-c")) {
        c = true;
    }
    else if (!s.compare("-o")) {
        o = true;
    }
  }
	cout << "nomFichier" << endl;
  string nomFichier(argv[argc-1]);
	ifstream myReadFile;
	myReadFile.open(nomFichier);
	string output="";
	string temp;
	if (myReadFile.is_open()) {
		myReadFile >> noskipws;
		while (!myReadFile.eof()) {
				getline(myReadFile,temp);
				output = output + temp;
		       // myReadFile >> output;
		}
	}
	myReadFile.close();
	ANTLRInputStream input(output);


	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.function();
	cout << "Avant visite de l'arbre" << endl;
	if(parser.getNumberOfSyntaxErrors() == 0){
		calc visitor;
		visitor.visit(tree);
		
		// Une fois l'AST construit, on le parcours pour renseigner la table des symboles
		list<Fonction*> fonctions = (list<Fonction*>)visitor.getFonctions();
		for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() ; ++it) 
		{
		  (*it)->generateST();
			cout << "creation cfg" << endl;
			CFG * cfg = new CFG((*it));
		  //cfg->genererIR();
		int compteur = 0;
			for(list<Instruction*>::iterator it2 = (*it)->getInstructions()->begin(); it2 != (*it)->getInstructions()->end(); it2++){
				cout << "instruction numero " << compteur++ << " " << (*it2)->toString() << endl;
				cout << (*it2)->buildIR(cfg);
				cout << endl;
			}
			ofstream myfiletest("./test.s");
		    	cout << "Generation code assembleur" << endl;
		  	cfg->genererCodeAssembleur(myfiletest);
			
			myfiletest.close();
			cout << "code assembleur terminé" << endl;
			
			  if (a) {
				  // Générer que si argument passé en option
				  (*it)->generateSA();
				  (*it)->processSA();
				  (*it)->displaySymbolTable();
				  cout << endl;
				  (*it)->displayStaticAnalysis();
				  cout << endl;
				  (*it)->displayWarnings();
				  cout << endl;
				  (*it)->displayErrors();
			  }
			  
			  if (c) {
		  	  // Générer que si argument passé en option
			    ofstream myfile("./main.s");
			    myfile << (*it)->genererCodeAssembleur() << endl;
			    myfile.close();
			  }
		}
	}else{
		cerr << "ERROR ! My tree is not visited" << endl;
	}

	return 0;
}
