#pragma once

#ifndef PLD_COMP_ENUM_H
#define PLD_COMP_ENUM_H

#ifndef YYTOKENTYPE
# define YYTOKENTYPE

typedef enum {
	VIDE = 0,
	INT = 1,
	CHAR =2,
	VOID = 3
} Type;
#endif
#endif //PLD_COMP_ENUM_H
