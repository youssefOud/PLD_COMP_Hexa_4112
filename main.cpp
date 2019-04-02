#ifdef DEBUG_ENABLE
    #define debug(debugString) std::cout << (debugString) << std::endl;
#else
    #define debug(debugString)
#endif

#include <iostream>
#include <fstream>
#include <string.h>
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
		}
	}
	myReadFile.close();
	ANTLRInputStream input(output);


	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.fichier();

	if(parser.getNumberOfSyntaxErrors() == 0){
		calc visitor;
		visitor.visit(tree);
		
		// Une fois l'AST construit, on le parcours pour renseigner la table des symboles
		list<Fonction*> fonctions = (list<Fonction*>)visitor.getFonctions();
		
		//A partir des fonctions que nous avons, nous nous assurons d'abord qu'il existe bien une fonction main ! 
		int numberOfMains =0;
		for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() && numberOfMains<2 ; ++it){
			if((*it)->getId() == "main"){
				numberOfMains++;
			}
		}
		if(numberOfMains==1){
			for(list<Fonction*>::iterator it=fonctions.begin() ; it!=fonctions.end() ; ++it) 
			{
				debug((*it)->toString());
			  	(*it)->generateST();
				CFG * cfg = new CFG((*it));
				for(list<Instruction*>::iterator it2 = (*it)->getInstructions()->begin(); it2 != (*it)->getInstructions()->end(); it2++){
					(*it2)->buildIR(cfg);
				}
				  (*it)->generateSA();
				  (*it)->processSA();

			  if (a) {
				  // Générer que si argument passé en option
				  (*it)->displaySymbolTable();
				  cout << endl;
				  (*it)->displayStaticAnalysis();
				  cout << endl;
				  (*it)->displayWarnings();
				  cout << endl;
				  (*it)->displayErrors();
			  }
			  
			  if (c && ((*it)->getNumberOfErrors()==0)) 
			  {
		  	  // Générer que si argument passé en option
			    nomFichier.replace(nomFichier.length()-2, 3,".s");
			    ofstream myfile(nomFichier);
			    cfg->genererCodeAssembleur(myfile);
			    myfile.close();
			  }else if ((*it)->getNumberOfErrors()>0 && c)
			  {
			    cerr << "Erreur ! Le fichier assembleur n'a pas été généré !" <<endl;
			  }
			}
		}
		else if(numberOfMains ==0){
			cerr << "Erreur ! Aucune fonction main n'a été trouvé !" <<endl;
		}
		else{
			cerr << "Erreur ! Plusieurs fonctions main ont été trouvé !" <<endl;
		}
	}
	else{
		cerr << "Erreur ! L'arbre est mal formé, il ne pourra pas être visité." <<endl;
	}
	return 0;
}
