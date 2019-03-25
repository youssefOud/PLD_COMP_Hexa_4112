grammar expr;

function: type ID '(' ')' '{' corps '}' ;

type : INT # typefct ;

right : ID # rightValueID
	| NBR # rightValueNBR ;

expression : expression ('*') expression # exprMult
	| expression ('+') expression # exprAdd
	| expression ('-') expression # exprMinus
	| '('expression')' # exprPar
	| right  # rightValue;

left : ID # leftValue ;

declare : type ids ';' # declaration ;

ids : ID # simpleId
	| ID ',' ids #multipleId ;

affect : (type left '=' expression ';')  # definition
	| (left '=' expression ';') # affectation ;

ret : RETURN expression ';' # return ;

corps : affect ret # corpsAffectRet
	| affect corps # corpsAffect
	| declare ret # corpsDeclareRet
	| declare corps # corpsDeclare
	| ret # corpsRetour
	| corps ';' # corpsRec ;

INT : 'int' ;
NBR : [0-9]+ ;
RETURN : 'return' ;
ID : [A-Za-z]+ ;
WS : [ \t\r\n] -> skip ;
