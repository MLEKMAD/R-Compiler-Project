#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

FILE* Fichier;

typedef enum _boolean{
	false,
	true
}boolean;


typedef enum _CODES_LEX{
	IF_TOKEN    , ELSE_TOKEN    , IFELSE_TOKEN,
    REPEAT_TOKEN  ,PRINT_TOKEN,
    WHILE_TOKEN , FUNCTION_TOKEN, FOR_TOKEN     ,
    IN_TOKEN    , NEXT_TOKEN    , BREAK_TOKEN   ,
    TRUE_TOKEN  , FALSE_TOKEN   , NULL_TOKEN   ,
    /// cluster 1
    INF_TOKEN   , NaN_TOKEN     ,NA_TOKEN       ,PLUS_TOKEN,
    NA_INTEGER__TOKEN  , NA_REAL__TOKEN , NA_COMPLEX__TOKEN,
    NA_CHARACTER__TOKEN , POINT_TOKEN    ,MOINS_TOKEN,
    MULT_TOKEN, DIV_TOKEN,EXPONENT_TOKEN ,MODULUS_TOKEN ,INT_DIV_TOKEN ,POWER_TOKEN,
    /// Arithmetic Operators

    /// relational operators
    LT_TOKEN ,GT_TOKEN ,LTE_TOKEN ,
    GTE_TOKEN ,EQ_TOKEN ,NOT_EQ_TOKEN  ,STRING_TOKEN,
    ///logical operators
    LOGNOT_TOKEN ,ELEMENTWISE_LOGAND_TOKEN ,LOGAND_TOKEN,
    ELEMENTWISE_LOGOR_TOKEN ,LOGOR_TOKEN ,
    ///cluster 2
    PO_TOKEN    , PF_TOKEN  ,PI_TOKEN,OCB_TOKEN,CCB_TOKEN,VIR_TOKEN,
    OSB_TOKEN,CSB_TOKEN,DEUX_POINTS_TOKEN,BOOLEAN_TOKEN,

    ///cluster assignment
    EGAL_LEFT_TOKEN ,EGAL2_LEFT_TOKEN,EGAL_lEFT_TOKENT,
    EGAL1_RIGHT_TOKEN,EGAL2_RIGHT_TOKEN,ID_TOKEN,ERREUR_TOKEN,
	PV_TOKEN,FIN_TOKEN , NUM_TOKEN,RETURN_TOKEN,BY_TOKEN,OUT_TOKEN,LENGTH_TOKEN,TIMES_TOKEN,EACH_TOKEN,REP_TOKEN,SEQ_TOKEN,C_TOKEN
}CODES_LEX;
typedef  struct {
	CODES_LEX CODE;
	char nom[30];
	char name[30];
	} TSym_Cour;
TSym_Cour SYM_COUR;

// Type of the symbols that will be stored in the tanle of symbols
typedef enum _symbol_type {
	TVAR,
	TCHR,
	TINT,
	TFLT,


} symbol_type;


// Symbol structure that will be stored in the table of symbols
struct _stored_symbol {
	char nom[30];
	enum _symbol_type type;
	int address;
	int length;
	boolean is_const;
	//int offset;


};

// Variable declaration
FILE* file;
char output_file_name[20];


char current_char;


int symbol_table_size;
int symbol_table_max_size;
struct _stored_symbol *symbol_table;


int offset;

int state;
int current_address;

int address_offset;

symbol_type current_expression_type;




#endif










