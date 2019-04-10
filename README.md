# PLD_COMP_Hexa_4112

## Description

    Ce projet est réalisé dans le cadre du PLD COMP au sein du département informatique de l'INSA Lyon. 
    Il s'agit d'un compilateur d'un sous-ensemble du langage C. Il est écrit en C++ et utilise ANTLR4.
    Le projet est réalisé par 7 élèves de quatrième année en utilisant la méthode Agile.

## Outils nécessaires pour utiliser le compilateur

    ANTLR4 : Pour ce projet, nous utilisons la version 4.7.2. Cet outil n'est pas indispensable pour utiliser le compilateur mais il l'est si vous souhaiter contribuer et améliorer la grammaire prise en charge du compilateur.

## Lancement du compilateur

    Un script est disponible au premier niveau de l'arborescence : **"nom du script.sh"**. Vous pouvez le lancer avec différentes options
    * '-a' : Option permettant de faire une analyse statique du code et de détecter les warnings et les erreurs.
    * '-c' : Option permettant de générer du code assembleur dans un fichier '.s'. Ce fichier portera le nom du fichier test. 
    _Exemple_ : Si le fichier test porte le nom "operationArithmetique.c", le fichier compilé aura le nom suivant : "operationArithmetique.s"
    * '-o' : Elle permet d'indiquer des optimisations possibles dans le code compilé.
    
    En plus de ces options, vous devez spécifier en dernier argument le nom du fichier à analyser. Les seuls fichiers autorisés sont de la forme **/chemin/vers/fichier/nomFichier.c**. 
    
    Pour lancer le script : ouvrir un terminal dans le dossier source et taper la ligne : **./mongcc.sh [-a] [-o] [-c] chemin/vers/fichier/nomFichierTest.c**
    
## Fonctionnalités actuelles du compilateur

    Actuellement, le compilateur est capable de gérer :
    * Une seule fonction
    * Le type int
    * Déclaration d'une variable : _int a;_
    * Définition d'une variable : _int a = 42;_ ou _int a = b;_
    * Affectation d'une variable : _a = b;_ ou _a = 42;_
    * Addition
    * Soustraction
    * Multiplication
    * Parenthèse : _a = (42);_
    * Opérations arithmétiques combinant les opérations précédentes et ordre de priorité respecté
    * Déclaration multiple : _int a,b,c;_
	* Négation
	* Condition If Else : attention, notre compilateur ne supporte pas le else if et juste le if
    
    Il est capable de détecter les warnings suivants :
    * les variables non utilisées, 
    * les variables non déclarées,
	* Absence de return dans une fonction qui est censée retourner une quelque chose,
	* S'il y a un retour pour une fonction void,
	* Fonction non définie utilisée

	Il est capable de détecter les erreurs suivantes :
    * Déclarations multiples d’une variable,
	* Variable utilisée mais non déclarée
	* Variable utilisée mais non initialisée
	* Multiples définitions de fonctions
	* S'il n'y aucun ou plusieurs main
	
	Il est également capable de donner les optimisations possibles du code suivantes :
	* Expression constante : _int a = 2+3+4+5_ 
	* Boucle infinie :  _while(3==2+1)_
	* Boucle jamais atteinte : _while(1==2)_   
	
    Dans le cas où la syntaxe n'est pas respectée dans le fichier, une erreur sera relevée.
    
## Tests automatiques

    Il est possible de lancer un set de tests automatiques afin de vérifier après chaque changement que le compilateur fonctionne toujours correctement. Pour le faire, il faut lancer le script test.py en tapant la commande suivante : python test.py . Par ailleurs, le makefile contient une cible "test" qui crée l'executable et lance les jeux des tests (lancer la commande : make test).
    Vous obtiendrez une liste contenant le nom du fichier testé suivi d'un "True" ou "False" spécifiant si le test est passé ou pas, le code testé, ainsi que les résultats obtenus et attendus.
