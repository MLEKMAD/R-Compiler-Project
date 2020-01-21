
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lex.h"

/**
*
* @author : Hatim LAHLALI
* @author : Mohamed LEKMAD
* @author : khaoula LOUDIYI
* @author : Oussama EL KHALIDA
**/

#define Max_NBRE 20
#define TAILLE_TAB_SYMBOLE 50


CODE_LEX LAST;
Token tabToken[] = {
    ///clust
    {IF_Token ,"if"},
    {ELSE_Token ,"else"},
    {IFELSE_Token," ifelse "},
    {repeat_Token ,"repeat"},
    {PRINT_Token ,"print"},
    {WHILE_Token ,"while"},
    {FUNCTION_Token ," function"},
    {FOR_Token ,"for"},
    {in_Token ,"in"},
    {next_Token ,"next"},
    {break_Token ,"break"},
    {TRUE_Token,"true"},
    {FALSE_Token,"false"},
    {NULL_Token,"null"},
    ///cluster 1

    {INF_Token,"INF"},
    {NaN_Token,"NaN"},
    {NA_Token,"Na"},
    {NA_integer__Token,"NA_integer_"},
    {NA_real__Token,"NA_real_"},
    {NA_complex__Token,"NA_complex_"},
    {NA_character__Token,"NA_character_"},
    {Point_Token,"point"},

    /// Arithmetic Operators
    {PLUS_Token ,"+"},
    {MOINS_Token ,"-"},
    {MULT_Token ,"*"},
    {DIV_Token,"/"},
    {EXPONENT_Token ,"^"},
    {MODULUS_Token ,"%%"},
    {INT_DIV_Token ,"%/%"},
    /// relational operators
    {LT_Token ,"<"},
    {GT_Token ,">"},
    {LTE_Token ,"<="},
    {GTE_Token ,">="},
    {EQ_Token ,"=="},
    {NOT_EQ_Token ,"!="},
    /// logical operators
    {LogNOT ,"!"},
    {Elementwise_LogAND_Token ,"&"},
    {LogAND_Token ,"&&"},
    {Elementwise_LogOR_Token ,"|"},
    {LogOR_Token ,"||"},
    /// cluster assignment
    {EGAL1_left_Token ,"="},
    {EGAL2_left_Token ,"<-"},
    {EGAL3_left_Token ,"<<-"},
    {EGAL1_right_Token ,"->"},
    {EGAL2_right_Token ,"->>"},
     ///cluster 4
    {PO_Token ,"("},
    {PF_Token ,")"},
    {PI_Token,"pi"},


};
void Check_Token() {
  if((strcmp("if",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IF_TOKEN ;
  }
  else if((strcmp("else",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = ELSE_TOKEN ;
  }
  else if((strcmp("ifelse",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = IFELSE_Token ;
  }
  else if((strcmp("repeat",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = repeat_Token ;
  }
  else if((strcmp("print",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = PRINT_Token ;
  }
  else if((strcmp("function",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FUNCTION_Token ;
  }
  else if((strcmp("for",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FOR_Token ;
  }
  else if((strcmp("while",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = WHILE_TOKEN ;
  }
  else if((strcmp("in",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = in_Token ;
  }
  else if((strcmp("next",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = next_Token ;
  }
  else if((strcmp("break",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = break_Token ;
  }
  else if((strcmp("true",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = TRUE_Token ;
  }
  else if((strcmp("false",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = FALSE_Token ;
  }
  else if((strcmp("null",Token_Cour->WORD)==0)) {
    Token_Cour->TOKEN = NULL_Token ;
  }
  else {
    Token_Cour->TOKEN = ID_TOKEN ;
  }
}
static void next_char() {
	Car_Cour = fgetc(file);
}
void read_word() {
	// Moving to the next character
	int count_char=0;
	next_char();
    count_char++;
	// Looping through the characters
	while (
        ('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')||('0'<=Car_Cour && Car_Cour<='9') ||Car_Cour=='.'
        ) {
		next_char();
		Token *Token_Cour;
	}
	// Assigning the token
	assign_token(NOTHING);
}

void Next_Word() {
  int count_car = 0 ;
  *(Token_Cour->WORD)=Car_Cour;
  count_car++;
  Next_Car();
  while(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')||('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD)=Car_Cour;
    count_car++;
    Next_Car();
  }
}
void Next_Number() {
  int count_car = 0 ;
  *(Token_Cour->WORD)=Car_Cour;
  Next_Car();
  while(('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(count_car>=11) {}
  Token_Cour->TOKEN = NUM_TOKEN ;
}

void Next_Sym() {
  Token_Cour->TOKEN = NULL_TOKEN ;
  Token_Cour->WORD=memset(Token_Cour->WORD,'\0',sizeof(Token_Cour->WORD));
  if((Car_Cour==10)||(Car_Cour==32)) { // 10 means line feed  32 space
    Next_Car();
  }
  else if(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')) {
    Next_Word();
  }
  else if('0'<=Car_Cour && Car_Cour<='9') {
    Next_Number();
  }
  else if(Car_Cour == 46) {
    Token_Cour->TOKEN = Point_Token ;
    *Token_Cour->WORD = '.' ;
    Next_Car();
  }
  else if(Car_Cour == 43) {
    Token_Cour->TOKEN = PLUS_Token ;
    *Token_Cour->WORD = '+' ;
    Next_Car();
  }
  else if(Car_Cour == 45) {
    Token_Cour->TOKEN = MOINS_Token ;
    *Token_Cour->WORD = '-' ;
    Next_Car();
  }
  else if(Car_Cour == 42) {
    Token_Cour->TOKEN = MULT_Token ;
    *Token_Cour->WORD = '*' ;
    Next_Car();
  }
  else if(Car_Cour == 47) {
    Token_Cour->TOKEN = DIV_Token ;
    *Token_Cour->WORD = '/' ;
    Next_Car();
  }
  else if(Car_Cour == 40) {
    Token_Cour->TOKEN = PO_Token ;
    *Token_Cour->WORD = '(' ;
    Next_Car();
  }
  else if(Car_Cour == 41) {
    Token_Cour->TOKEN = PF_Token ;
    *Token_Cour->WORD = ')' ;
    Next_Car();
  }
  else if(Car_Cour == 60) {
    Token_Cour->TOKEN = LT_Token ;
    *Token_Cour->WORD = '<' ;
    Next_Car();
  }
  else if(Car_Cour == 60) {
    Token_Cour->TOKEN = GT_Token ;
    *Token_Cour->WORD = '>' ;
    Next_Car();
  }
  else if(Car_Cour == 33) {
    Token_Cour->TOKEN = LogNOT ;
    *Token_Cour->WORD = '!' ;
    Next_Car();
  }
  else if(Car_Cour == 38) {
    Token_Cour->TOKEN = Elementwise_LogAND_Token ;
    *Token_Cour->WORD = '&' ;
    Next_Car();
  }
  else if(strcmp(Car_Cour,'|') ) { //check this
    Token_Cour->TOKEN = Elementwise_LogOR_Token ;
    *Token_Cour->WORD = '|' ;
    Next_Car();
  }
  else if(strcmp(Car_Cour,'|')) {
    next_char();
    if(strcmp(Car_Cour,'|')){
    Token_Cour->TOKEN = LogOR_Token ;
    *Token_Cour->WORD = "||" ;
    Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }

  }
  else if(Car_Cour == 38) {
    next_char();
    if(Car_Cour == 38){
    Token_Cour->TOKEN = Elementwise_LogAND_Token ;
    *Token_Cour->WORD = "&&" ;
    Next_Car();
    }
    else {
    Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='=';
    }
  }
  else if(Car_Cour == 37) {
    Next_Car();
    if(Car_Cour ==47){
        Next_Car();
        if(Car_Cour ==37) {
          Token_Cour->TOKEN = MODULUS_Token ;
          Token_Cour->WORD=strcpy(Token_Cour->WORD,"%/%");
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
    Token_Cour->TOKEN = EGAL1_left_Token ;
    *Token_Cour->WORD = '=' ;
    Next_Car();
  }
  else if(Car_Cour == 61) {
    Next_Car();
    if(Car_Cour ==61) {
      Token_Cour->TOKEN = EQ_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"==");
      Next_Car();
    }
    else {
        Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='=';
    }
  }
  else if(Car_Cour == 33) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = NOT_EQ_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"!=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='!';
    }
  }
  else if(Car_Cour == 37) {
    Next_Car();
    if(Car_Cour ==37) {
      Token_Cour->TOKEN = MODULUS_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"%%");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = LTE_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"<=");
      Next_Car();
    }
    else{
           Token_Cour->TOKEN = SUP_TOKEN ;
          *Token_Cour->WORD='<';
        }
  }
  else if(Car_Cour == 62) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = GTE_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,">=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='>';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 60) {
     Next_Car();
        if(Car_Cour=61){
          Token_Cour->TOKEN = EGAL3_left_Token ;
          Token_Cour->WORD=strcpy(Token_Cour->WORD,"<<=");
          Next_Car();
        }
        else{
            Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
      Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='>';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour == 61) {
      Token_Cour->TOKEN = EGAL2_left_Token ;
      Token_Cour->WORD=strcpy(Token_Cour->WORD,"<=");
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = SUP_TOKEN ;
      *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 45) {
    Next_Car();
    if(Car_Cour ==62){
          Token_Cour->TOKEN = EGAL1_right_Token ;
          Token_Cour->WORD=strcpy(Token_Cour->WORD,"->");
          Next_Car();

    }
    else {
        Token_Cour->TOKEN = SUP_TOKEN ;
        *Token_Cour->WORD='-';
    }
  }
  else if(Car_Cour == 60) {
    Next_Car();
    if(Car_Cour ==60){
        Next_Car();
        if(Car_Cour ==45) {
          Token_Cour->TOKEN = EGAL3_left_Token ;
          Token_Cour->WORD=strcpy(Token_Cour->WORD,"<<-");
          Next_Car();
        }
        else {
        Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
           Token_Cour->TOKEN = SUP_TOKEN ;
          *Token_Cour->WORD='<';
    }
  }
  else if(Car_Cour == 45) {
    Next_Car();
    if(Car_Cour ==62){
        Next_Car();
        if(Car_Cour ==62) {
          Token_Cour->TOKEN = EGAL2_right_Token ;
          Token_Cour->WORD=strcpy(Token_Cour->WORD,"->>");
          Next_Car();
        }
        else {
        Token_Cour->TOKEN = ERREUR_TOKEN ;
        }
    }
    else {
           Token_Cour->TOKEN = SUP_TOKEN ;
          *Token_Cour->WORD='>';
    }
  }
  else if(Car_Cour == 123) { //end of file
    Next_Car();
    if(Car_Cour == 42) {
      Break_Comment();
      Next_Car();
    }
    else {
      Token_Cour->TOKEN = ERREUR_TOKEN ;
    }
  }
  else {
    Next_Car();
  }
}

