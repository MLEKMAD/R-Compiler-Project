#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

/*
* DECLARATION DES CLASSES LEXICALES
*/




typedef enum {

    IF_TOKEN    , ELSE_TOKEN    , IFELSE_TOKEN,
    REPEAT_TOKEN  ,PRINT_TOKEN,
    WHILE_TOKEN , FUNCTION_TOKEN, FOR_TOKEN     ,
    IN_TOKEN    , NEXT_TOKEN    , BREAK_TOKEN   ,
    TRUE_TOKEN  , FALSE_TOKEN   , NULL_TOKEN   ,
    /// cluster 1
    INF_TOKEN   , NaN_TOKEN     ,NA_TOKEN       ,PLUS_TOKEN,
    NA_INTEGER__TOKEN  , NA_REAL__TOKEN , NA_COMPLEX__TOKEN,
    NA_CHARACTER__TOKEN , POINT_TOKEN    ,MOINS_TOKEN,
    MULT_TOKEN, DIV_TOKEN,EXPONENT_TOKEN ,MODULUS_TOKEN ,INT_DIV_TOKEN ,
    /// Arithmetic Operators

    /// relational operators
    LT_TOKEN ,GT_TOKEN ,LTE_TOKEN ,
    GTE_TOKEN ,EQ_TOKEN ,NOT_EQ_TOKEN  ,
    ///logical operators
    LOGNOT_TOKEN ,ELEMENTWISE_LOGAND_TOKEN ,LOGAND_TOKEN,
    ELEMENTWISE_LOGOR_TOKEN ,LOGOR_TOKEN ,
    ///cluster 2
    PO_TOKEN    , PF_TOKEN      ,PI_TOKEN,

    ///cluster assignment
    EGAL_LEFT_TOKENR ,EGAL2_LEFT_TOKEN,EGAL_lEFT_TOKENT,
    EGAL1_RIGHT_TOKEN,EGAL2_RIGHT_TOKEN,ID_TOKEN,ERREUR_TOKEN
    } CODE_LEX ;
CODE_LEX LAST;
typedef struct {
    CODE_LEX TOKEN;
    char WORD[20];

} Token;
Token *Token_Cour;
FILE *fl;
extern Token tabToken[];
void Check_token();
void Next_Car();
void read_word();
void Next_Sym();

#endif // LEX_H_INCLUDED
