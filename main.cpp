#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "exprBaseVisitor.h"
#include "compilateur.h"

using namespace antlr4;
using namespace std;

int main(int arg, const char ** argv) {
  string nomFichier = argv[1];
  ifstream fichier(nomFichier, ios::in);
  string monCode = "";
  if (fichier) {
    getline(fichier, monCode);
    string ligne = "";
    while (!fichier.eof()) {
      getline(fichier,ligne);
      monCode = monCode + ligne;
    }
    fichier.close();
  }
  cout << monCode << endl;
  ANTLRInputStream input(monCode);
	exprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	exprParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();
	
	Compilateur visitor;
	int resultat = (int) visitor.visit(tree);

	cout << "Resultat " << resultat << endl;

	return 0;
}
