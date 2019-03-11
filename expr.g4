grammar expr;
prog: type nomfonction '()' '{' code '}' # proggeneral;
type: 'int' # typevar;
nomfonction: NOM # nom;
code: 'return' INT ';' # codefonction;
WS : [ \t\r\n] -> skip ;
INT	: [0-9]+ ;
NOM	: [A-z]+ ;