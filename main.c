#include <stdio.h>
#include <stdlib.h>





int main()
{
  printf("Hello world!\n");
  file=fopen("test.txt","a+");
  Token_Cour = (Token*)malloc(sizeof(Token));
  Token_Cour->WORD = (char*)malloc(21);
  Next_Char();
  while(Car_Cour != EOF) {
    Next_Sym();
    if(Token_Cour->TOKEN != NULL_TOKEN) {
      printf("%s ----> %s\n",tabToken[Token_Cour->TOKEN].TOKENS,Token_Cour->WORD);
    }
  }
  printf("lecture is finished");
  return 0;
}
