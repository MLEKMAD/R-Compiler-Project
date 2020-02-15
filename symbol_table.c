
#include "symbol_table.h"

//SYMBOL TABLE FUNCTIONS


/*
 * Initializing the symbol table
 */
void init_symbol_table() {
	symbol_table_size = 0;
	symbol_table_max_size = 10;
	current_address = 0;

	symbol_table = malloc(symbol_table_max_size * sizeof(struct _stored_symbol));
}


/*
 * Change the size of the symbol table
 */
static void change_size() {
	symbol_table_max_size += 10;
	symbol_table = realloc(symbol_table, symbol_table_max_size * sizeof(struct _stored_symbol));
}


/*
 * Adds the symbol to the symbol table
 */
void add_symbol(symbol_type t) {
	// Checking first that the symbol extsts in the symbol table

		// If there are no more space in the symbol table
		if (symbol_table_size > symbol_table_max_size) {
			change_size();
		}
		// adding the symbol to the table
		strcpy(symbol_table[symbol_table_size].nom, SYM_COUR.name);
		symbol_table[symbol_table_size].type     = t;


		// Incrementing the symbol table size
		symbol_table_size++;

}


/*
 * Check if the current symbol already exists in the symbol table
 * return the index of the symbol in the table if it exists
 * or return -1 if the symbol does not exists in the table
 */
int symbol_exists() {
	for (int i = 0; i < symbol_table_size; i++) {
		if ( strcmp(symbol_table[i].nom, SYM_COUR.name) == 0 )
			return i;
	}

	return -1;
}




symbol_type get_type() {
	for (int i = 0; i < symbol_table_size; i++) {
		if ( strcmp(symbol_table[i].nom, SYM_COUR.nom) == 0 )
			return symbol_table[i].type;
	}

	return -1;
}

/*
 * Check if a specific symbol already exists in the symbol table
 * return the index of the symbol in the table if it exists
 * or return -1 if the symbol does not exists in the table
 */
int _specific_symbol_exists(char *symbol) {
	for (int i = 0; i < symbol_table_size; i++) {
		if ( strcmp(symbol_table[i].nom, symbol) == 0 )
			return i;
	}

	return -1;
}


/*
 * Printing into the screen the symbol table
 */
void show_symbol_table() {
	printf("\n\n");
	printf("====================================\n");
	printf("=== Table des symboles =============\n");
	printf("====================================\n");
	printf("  Symbole  | Tp |  \n");
	printf("------------------------------------\n");

	for(int i = 0; i < symbol_table_size; i++) {
		if(strcmp(symbol_table[i].nom,"0")!=0)
			printf("%10s | %2i |   \n", symbol_table[i].nom, symbol_table[i].type);
	}
}

/*
 * Changing the last symbol typ
 */
void set_last_symbol_type(symbol_type t) {
	symbol_table[symbol_table_size - 1].type = t;
}












void delete_symbol(){
	if(symbol_exists()!=-1){
		for(int i=0;i<symbol_table_size-1;i++){
		if(strcmp(symbol_table[i].nom,SYM_COUR.name) == 0){
			strcpy(symbol_table[i].nom,"0");
			symbol_table[i].type = TVAR;

			}

		}


	}
}
