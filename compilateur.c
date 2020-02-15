#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "global.h"
#include "analyseur_synthaxique.h"

int main(){
	Fichier=fopen("tes.r","r");

	Lire_Car();

	next_sym();
	if(!PROG()) printf("Error\n");
	else{printf("YEEEEEEEEEES\n");}


	fclose(Fichier);

	return 0;

}
