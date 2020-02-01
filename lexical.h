//
// Created by admin on 01/02/2020.
//

#ifndef R_COMPILER_PROJECT_LEXICAL_H
#define R_COMPILER_PROJECT_LEXICAL_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int  Car_Cour=0;

FILE* Fichier;

typedef  enum _boolean {
    false,true
}boolean;


typedef enum{
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
            PO_TOKEN    , PF_TOKEN      ,PI_TOKEN,OCB_TOKEN,CCB_TOKEN,VIR_TOKEN,
    OSB_TOKEN,CSB_TOKEN,

    ///cluster assignment
            EGAL_LEFT_TOKEN ,EGAL2_LEFT_TOKEN,EGAL_lEFT_TOKENT,
    EGAL1_RIGHT_TOKEN,EGAL2_RIGHT_TOKEN,ID_TOKEN,ERREUR_TOKEN,
    PV_TOKEN
}CODES_LEX;

typedef enum { FIN_TOKEN , NUM_TOKEN};

typedef  struct {
    CODES_LEX CODE;
    char nom[20];
} TSym_Cour;

TSym_Cour SYM_COUR;

typedef enum {
    ERR_CAR_INC, ERR_FICH_VID, ERR_ID_LONG , ERR_HORS_LANG , ERR_NBR_LONG
}Erreurs;

typedef struct {
    Erreurs CODE_ERR;
    char mes[40];
}Serreurs;

Serreurs MES_ERR[100]={{ERR_CAR_INC,"caractere inconnu"}, {ERR_FICH_VID,"fichier vide"},{ERR_ID_LONG,"IDF tres long" },{ERR_HORS_LANG,"caractere hors language" }, {ERR_NBR_LONG , "nbr tres grand"}};

void Lire_Car();
void Erreur(Erreurs ERR);
void lire_mots();
void lire_nbr();
void next_sym();


#endif //R_COMPILER_PROJECT_LEXICAL_H
