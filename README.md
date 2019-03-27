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
    * '-o' : Cette option n'est pas encore disponible. Elle permet d'optimiser le code compilé.
    
    En plus de ces options, vous devez spécifier en dernier argument le nom du fichier à analyser. Les seuls fichiers autorisés sont de la forme **/chemin/vers/fichier/nomFichier.c**. 
    
    Pour lancer le script : ouvrir un terminal dans le dossier source et taper la ligne : **./nomScript.sh [-a] [-o] [-c] nomFichierTest.c**
    
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
    
    Il est capable de détecter les erreurs/warnings suivants :
    * les variables non utilisées, 
    * les variables non déclarées
    * les variables utilisées mais non déclarées 
    * les variables utilisées mais non initialisées
    
    Dans le cas où la syntaxe n'est pas respecté dans le fichier, une erreur sera relevée
    
## Tests automatiques

    Il est possible de lancer un set de test afin de vérifier après chaque changement que le compilateur fonctionne toujours correctement. .... (TODO : à compléter)
