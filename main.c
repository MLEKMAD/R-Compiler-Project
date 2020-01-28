#include <stdio.h>
#include <stdlib.h>
#include "analyseur_lexical.c"



FILE *f1 = NULL;

int main()
{
    f1=fopen("test","a+");
  printf("Read file hahhahaha!");
  Token_Cour = (Token*)malloc(sizeof(Token));
  strcpy(Token_Cour->WORD,(char*)malloc(20));
  Next_Car();
  while(Car_Cour != EOF) {
    Next_Sym();
    if(Token_Cour->TOKEN != NULL_TOKEN) {
      printf("%s ----> %s\n",Token_Cour->TOKEN,Token_Cour->WORD);
    }
  }
  printf("lecture is finished");
  return 0;
}
