#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

/*
* DECLARATION DES CLASSES LEXICALES
*/




typedef enum {

    IF_TOKEN    , ELSE_TOKEN    , IFELSE_Token,
    repeat_Token  ,PRINT_Token ,
    WHILE_Token , FUNCTION_Token, FOR_Token     ,
    in_Token    , next_Token    , break_Token   ,
    TRUE_Token  , FALSE_Token   , NULL_Token    ,
    /// cluster 1
    INF_Token   , NaN_Token     ,NA_Token       ,
    NA_integer__Token   , NA_real__Token , NA_complex__Token,
    NA_character__Token , Point_Token    ,
    /// Arithmetic Operators
    PLUS_TOKEN,EXPONENT_Token,
    MOINS_TOKEN , MULT_Token    , DIV_Token ,
    INT_DIV_Token, MODULUS_Token,
    /// relational operators
    LT_Token ,GT_Token ,LTE_Token ,
    GTE_Token ,EQ_Token ,NOT_EQ_Token  ,
    ///logical operators
    LogNOT ,Elementwise_LogAND_Token ,LogAND_Token ,
    Elementwise_LogOR_Token ,LogOR_Token ,
    ///cluster 2
    PO_Token    , PF_Token      ,PI_Token,

    ///cluster assignment
    EGAL1_left_Token ,EGAL2_left_Token,EGAL3_left_Token,
    EGAL1_right_Token,EGAL2_right_Token
    } CODE_LEX ;

CODE_LEX LAST;



typedef struct {

    CODE_LEX CODE;

    char NOM[20];

} Token;
Token *Token_Cour


typedef enum{

    FALSE = 0,

    TRUE = 1

} boolean;



extern Token tabToken[];

void Check_Token;
static void next_char;
void read_word;
void Next_Sym;




#endif // LEX_H_INCLUDED
