grammar expr;

fichier : programme ;

programme : function programme # fctMult
	| function # fctUnique ;

appel : ID '('')'   # appelFuncSansParam
	| ID  '(' vars ')'  # appelFuncAvecParam ;

vars : expression # paramUnique
	| expression ',' vars # paramMult ;

function : typefct ID '(' defAppel ')' '{' corps '}' # fct 
	| typefct ID '(' ')' '{' corps '}' # fctSansParam ;

defAppel : type ID # defParamUnique
	| type ID ',' defAppel # defParamMult ;

typefct : INT # retourInt
	| VOID # retourVoid ;

type : INT # typeVarInt 
	| CHAR #typeVarChar;

right : ID # rightValueID
	| NBR # rightValueNBR 
	|  CARACTERE # rightValueCHAR ;

expression : expression ('*') expression # exprMult
	| ('-') expression # exprNeg
	| expression op = ('+'|'-') expression # exprAddMinus
	| '('expression')' # exprPar
	| right  # rightValue
	| appel # exprApp ;

left : ID # leftValue ;

declare : type ids ';' # declaration ;

ids : ID # simpleId
	| ID ',' ids #multipleId ;

affect : (type left '=' expression ';')  # definition
	| (left '=' expression ';') # affectation ;

ret : RETURN expression ';' # return ;

instruction : IF '(' expression ')' '{' corps '}' (ELSE '{' corps '}')? # ifInstr
	| WHILE '(' expression ')' '{' corps '}' # whileInstr 
	| affect  # instrAff
	| declare   # instrDec
	| expression ';'   # instrExpr 
	| ret # instrRet ;
	

corps : instruction # instr
	| instruction corps # instrCorps ;

VOID : 'void' ;
INT : 'int' ;
CHAR : 'char' ;
NBR : [0-9]+ ;
RETURN : 'return' ;
IF : 'if' ;
ELSE : 'else' ;
WHILE : 'while' ;
ID : [A-Za-z]+ ;
CARACTERE : '\''[A-Za-z]'\'' ;
WS : [ \t\r\n] -> skip ;

