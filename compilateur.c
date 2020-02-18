#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "global.h"
#include "analyseur_synthaxique.h"


int main(){
	Fichier=fopen("test3.r","r");
	current_line = 1;
	Lire_Car();

	next_sym();
	if(!PROG()) printf("Error in compilation\n");
	else{printf("Compiled Successfully\n");}


	fclose(Fichier);

	return 0;

}
