grammar expr;

function: type ID '(' ')' '{' corps '}' ;

type : INT # typefct ;

right : ID # rightValueID
	| NBR # rightValueNBR ;

left : ID # leftValue ;

declare : type ID ';' # declaration ;

affect : (type left '=' right ';')  # definition
	| (left '=' right ';') # affectation ;

ret : RETURN right ';' # return ;

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
