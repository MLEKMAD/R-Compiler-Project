
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analyseur_lexical.h"

/**
*
* @author : Hatim LAHLALI
* @author : Mohamed LEKMAD
* @author : khaoula LOUDIYI
* @author : Oussama EL KHALIFA
**/

#define Max_NBRE 20
#define TAILLE_TAB_SYMBOLE 50




FILE *f1;
char Car_Cour;
CODE_LEX LAST;
Token tabToken[] = {
    ///clust
    {IF_TOKEN ,"if"},
    {ELSE_TOKEN ,"else"},
    {IFELSE_TOKEN," ifelse "},
    {REPEAT_TOKEN ,"repeat"},
    {PRINT_TOKEN ,"print"},
    {WHILE_TOKEN ,"while"},
    {FUNCTION_TOKEN ," function"},
    {FOR_TOKEN ,"for"},
    {IN_TOKEN ,"in"},
    {NEXT_TOKEN ,"next"},
    {BREAK_TOKEN ,"break"},
    {TRUE_TOKEN,"true"},
    {FALSE_TOKEN,"false"},
    {NULL_TOKEN,"null"},
    ///cluster 1
    {INF_TOKEN,"INF"},
    {NaN_TOKEN,"NaN"},
    {NA_TOKEN,"Na"},
    {NA_INTEGER__TOKEN,"NA_integer_"},
    {NA_REAL__TOKEN,"NA_real_"},
    {NA_COMPLEX__TOKEN,"NA_complex_"},
    {NA_CHARACTER__TOKEN,"NA_character_"},
    {POINT_TOKEN,'.'},
    {PLUS_TOKEN ,'+'},
    {MOINS_TOKEN ,'-'},
    {MULT_TOKEN ,'*'},
    {DIV_TOKEN,'/'},
    {EXPONENT_TOKEN ,'^'},
    {MODULUS_TOKEN ,"%%"},
    {INT_DIV_TOKEN ,"%/%"},
    /// relational operators
    {LT_TOKEN ,'<'},
    {GT_TOKEN ,'>'},
    {LTE_TOKEN ,"<="},
    {GTE_TOKEN ,">="},
    {EQ_TOKEN ,"=="},
    {NOT_EQ_TOKEN ,"!="},
    /// logical operators
    {LOGNOT_TOKEN ,'!'},
    {ELEMENTWISE_LOGAND_TOKEN ,'&'},
    {LOGAND_TOKEN ,"&&"},
    {ELEMENTWISE_LOGOR_TOKEN ,'|'},
    {LOGOR_TOKEN ,"||"},
    /// cluster assignment
    {EGAL_LEFT_TOKENR ,'='},
    {EGAL2_LEFT_TOKEN ,"<-"},
    {EGAL_lEFT_TOKENT ,"<<-"},
    {EGAL1_RIGHT_TOKEN ,"->"},
    {EGAL2_RIGHT_TOKEN ,"->>"},
     ///cluster 4
    {PO_TOKEN ,'('},
    {PF_TOKEN ,')'},
    {PI_TOKEN,"pi"}
};
void Check_token() {
  if((strcmp("if",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IF_TOKEN ;
  }
  else if((strcmp("else",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = ELSE_TOKEN ;
  }
  else if((strcmp("ifelse",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IFELSE_TOKEN ;
  }
  else if((strcmp("repeat",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = REPEAT_TOKEN ;
  }
  else if((strcmp("print",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = PRINT_TOKEN ;
  }
  else if((strcmp("function",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FUNCTION_TOKEN ;
  }
  else if((strcmp("for",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FOR_TOKEN ;
  }
  else if((strcmp("while",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = WHILE_TOKEN ;
  }
  else if((strcmp("in",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IN_TOKEN ;
  }
  else if((strcmp("next",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = NEXT_TOKEN ;
  }
  else if((strcmp("break",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = BREAK_TOKEN ;
  }
  else if((strcmp("true",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = TRUE_TOKEN ;
  }
  else if((strcmp("false",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FALSE_TOKEN ;
  }
  else if((strcmp("null",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = NULL_TOKEN ;
  }
  else {
    Token_Cour->TOKEN = ID_TOKEN ;
  }
}

void Next_Car() {
	Car_Cour = fgetc(f1);
}
void Next_Word() {
  int count_car = 0 ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  count_car++;
  Next_Car();
  while(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')||('0'<=Car_Cour && Car_Cour<='9') ||Car_Cour=='.') {
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }//lecturre faussee
  Check_token();
}

void Next_Sym() {
  Token_Cour->TOKEN = NULL_TOKEN ;
  strcpy(Token_Cour->WORD,memset(Token_Cour->WORD,'\0',sizeof(Token_Cour->WORD)));
  if((Car_Cour==10)||(Car_Cour==32)) { // 10 means line feed  32 space
    Next_Car();
  }
  else if(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z') || ('0'<=Car_Cour && Car_Cour<='9') ||Car_Cour=='.') {
    Next_Word();
  }
  else if(Car_Cour == 46) {
    Token_Cour->TOKEN = POINT_TOKEN ;
    *Token_Cour->WORD = '.' ;
    Next_Car();
  }
  else if(Car_Cour == 43) {
    Token_Cour->TOKEN = PLUS_TOKEN ;
    *Token_Cour->WORD = '+' ;
    Next_Car();
  }
  else if(Car_Cour == 45) {
    Token_Cour->TOKEN = MOINS_TOKEN;
    *Token_Cour->WORD = '-' ;
    Next_Car();
  }
  else if(Car_Cour == 42) {
    Token_Cour->TOKEN = MULT_TOKEN ;
    *Token_Cour->WORD = '*' ;
    Next_Car();
  }
  else if(Car_Cour == 47) {
    Token_Cour->TOKEN = DIV_TOKEN ;
    *Token_Cour->WORD = '/' ;
    Next_Car();
  }
  else if(Car_Cour == 40) {
    Token_Cour->TOKEN = PO_TOKEN ;
    *Token_Cour->WORD = '(' ;
    Next_Car();
  }
  else if(Car_Cour == 41) {
    Token_Cour->TOKEN = PF_TOKEN ;
    *Token_Cour->WORD = ')' ;
    Next_Car();
  }
  else if(Car_Cour == 60) {
    Token_Cour->TOKEN = LT_TOKEN ;
    *Token_Cour->WORD = '<' ;
    Next_Car();
  }
  else if(Car_Cour == 60) {
    Token_Cour->TOKEN = GT_TOKEN ;
    *Token_Cour->WORD = '>' ;
    Next_Car();
  }
  else if(Car_Cour == 33) {
    Token_Cour->TOKEN = LOGNOT_TOKEN ;
    *Token_Cour->WORD = '!' ;
    Next_Car();
  }
  else if(Car_Cour == 38) {
    Token_Cour->TOKEN = ELEMENTWISE_LOGAND_TOKEN ;
    *Token_Cour->WORD = '&' ;
    Next_Car();
  }
  else if(Car_Cour =='|' ) {
    Token_Cour->TOKEN = ELEMENTWISE_LOGOR_TOKEN ;
    *Token_Cour->WORD = '|' ;
    Next_Car();
  }
  else if(Car_Cour =='|') { //CHECK THIS LATER
    Next_Car();
    if(Car_Cour =='|'){
    Token_Cour->TOKEN = LOGOR_TOKEN ;
    strcpy(Token_Cour->WORD,(char[]){"||"});
    Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }

  }
  else if(Car_Cour == 38) {
    Next_Car();
    if(Car_Cour == 38){
    Token_Cour->TOKEN = ELEMENTWISE_LOGAND_TOKEN ;
    strcpy(Token_Cour->WORD,(char[]){"&&"});
    Next_Car();
    }
    else {
    Token_Cour->TOKEN = ELEMENTWISE_LOGAND_TOKEN ;
    *Token_Cour->WORD='&';
    }
  }
  else if(Car_Cour == 37) {
    Next_Car();
    if(Car_Cour ==47){
        Next_Car();
        if(Car_Cour ==37) {
          Token_Cour->TOKEN = MODULUS_TOKEN ;
          strcpy(Token_Cour->WORD,"%/%");
          Next_Car();
        }
        else {
        Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else if(Car_Cour == 61) {
    Token_Cour->TOKEN = EGAL_LEFT_TOKENR ;
    *Token_Cour->WORD ='=' ;
    Next_Car();
  }
  else if(Car_Cour == 61) {
    Next_Car();
    if(Car_Cour ==61) {
      Token_Cour->TOKEN = EQ_TOKEN ;
      strcpy(Token_Cour->WORD,"==");
      Next_Car();
    }
    else {
        Token_Cour->TOKEN = EGAL_LEFT_TOKENR ;
      *Token_Cour->WORD='=';
    }
  }
  else if(Car_Cour == 33) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = NOT_EQ_TOKEN ;
      strcpy(Token_Cour->WORD,"!=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = LOGNOT_TOKEN ;
      *Token_Cour->WORD='!';
    }
  }
  else if(Car_Cour == 37) {
    Next_Car();
    if(Car_Cour ==37) {
      Token_Cour->TOKEN = MODULUS_TOKEN ;
      strcpy(Token_Cour->WORD,"%%");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = LTE_TOKEN ;
      strcpy(Token_Cour->WORD,"<=");
      Next_Car();
    }
    else{
           Token_Cour->TOKEN = INF_TOKEN ;
          *Token_Cour->WORD='<';
        }
  }
  else if(Car_Cour == 62) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = GTE_TOKEN ;
      strcpy(Token_Cour->WORD,">=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = GT_TOKEN ;
      *Token_Cour->WORD='>';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 60) {
     Next_Car();
        if(Car_Cour=45){
          Token_Cour->TOKEN = EGAL_lEFT_TOKENT ;
          strcpy(Token_Cour->WORD,"<<-");
          Next_Car();
        }
        else{
            Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
      Token_Cour->TOKEN = LT_TOKEN ;
      *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = EGAL2_LEFT_TOKEN ;
      strcpy(Token_Cour->WORD,"<=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = LT_TOKEN ;
      *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 45) {
    Next_Car();
    if(Car_Cour ==62){
          Token_Cour->TOKEN = EGAL1_RIGHT_TOKEN ;
          strcpy(Token_Cour->WORD,"->");
          Next_Car();

    }
    else {
        Token_Cour->TOKEN = MOINS_TOKEN ;//*********************
        *Token_Cour->WORD='-';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour ==60){
        Next_Car();
        if(Car_Cour ==45) {
          Token_Cour->TOKEN = EGAL_lEFT_TOKENT ;
          strcpy(Token_Cour->WORD,"<<-");
          Next_Car();
        }
        else {
        Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
           Token_Cour->TOKEN = LT_TOKEN ;
          *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 45) {
    Next_Car();
    if(Car_Cour ==62){
        Next_Car();
        if(Car_Cour ==62) {
          Token_Cour->TOKEN = EGAL2_RIGHT_TOKEN ;
          strcpy(Token_Cour->WORD,"->>");
          Next_Car();
        }
        else {
        Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
           Token_Cour->TOKEN = GT_TOKEN ;
          *Token_Cour->WORD='>';
    }
  }
  else {
    Next_Car();
  }
}

