#ifndef PSEUDO_CODE_H
#define PSEUDO_CODE_H

#include "global.h"

                        //code generator



typedef enum _pcode_inst {
	ADD, /* Perform addition on the top spots of the stack */
	SUB, /* Perform substration on the top spots of the stack */
	MUL, /* Perform multiplication on the top spots of the stack */
	DIV, /* Perform division on the top spots of the stack */
	EQL, /* Check if the the two spots on the top of the stack are equal */
	NEQ, /* Check if the the two spots on the top of the stack are not equal */
	GTR,
	LSS,
	GEQ,
	LEQ,
	PRF,
	RDF,
	INT, /* Asks for a number of memory spots to be reserved */
	LDI,
	LDA, // Chargement de l'adresse
	LDV, // Chargement de la valeur
	STO, // Stockage de la valeur dans une adresse
	BRN,
	BZE,
	HLT, /* End of the program */
	NOP, /* No operation */
	PRI,
	PRC,
	NEG, /* Change the number to its negative */
	NBZ, /* Branch if not equal (the contrary of the BZE) */
	SPD, /* Instruction to skip the procedure or function definition */
	RTS, /* Return to address in the stack */
	JSR, /* Jump to subroutine and add the return address to the stack */
	FRE, /* Freeing the a number of memory spots in the pile */
	DUP, /* Duplicate the top of the stack */
} pcode_inst;

static char inst_table[30][10] = {
	"ADD", /* Perform addition on the top spots of the stack */
	"SUB", /* Perform substration on the top spots of the stack */
	"MUL", /* Perform multiplication on the top spots of the stack */
	"DIV", /* Perform division on the top spots of the stack */
	"EQL", /* Check if the the two spots on the top of the stack are equal */
	"NEQ", /* Check if the the two spots on the top of the stack are not equal */
	"GTR",
	"LSS",
	"GEQ",
	"LEQ",
	"PRF",
	"RDF",
	"INT", /* Asks for a number of memory spots to be reserved */
	"LDI",
	"LDA", // Chargement de l'adresse
	"LDV", // Chargement de la valeur
	"STO", // Stockage de la valeur dans une adresse
	"BRN",
	"BZE",
	"HLT", /* End of the program */
	"NOP", /* No operation */
	"PRI",
	"PRC",
	"NEG", /* Change the number to its negative */
	"NBZ",
	"SPD",
	"RTS",
	"JSR",
	"FRE",
	"DUP",
};


/**
 * The structure that stores the a line of the pseudo code
 */
typedef struct _pcode_line {
	int line_number;
	pcode_inst inst;
	float parameter;
} pcode_line;

/**
 * The struct to store the linked list of Pcode instructions
 */
typedef struct _node {
	struct _node *previous;
	pcode_line line;
	struct _node *next;
} node;



int line_number;
node *pcode;
node *current_pcode;



/**
 * Function prototypes
 */

/* init pseudo code structure */
void _pseudo_code_init();

/**
 * add inst with parameter
 * to add an instruction that doesn't need a parameter
 * fill the parameter option with '0'
 */
void _pseudo_code_add_inst(pcode_inst inst, float param);

/* Writing pseudo code into a file in binary format */
void _pseudo_code_write();

/* Writing pseudo code into a file in text format */
void _pseudo_code_write_text();

/* Reading pseudo code from file */
void _pseudo_code_read_text();

/* Printing the pseudo code */
void _pseudo_code_print();

/* Printing the pseudo code in the text format */
void _pseudo_code_print_text();

/* Adding the parameter to the BZE instruction */
void _pseudo_code_fix_bze();

/* Adding the parameter to the NBZ instruction */
void _pseudo_code_fix_nbz();

/* Adding the parameter to the BRN instruction */
void _pseudo_code_fix_brn();

/* Adding the parameter to the the SPD instruction */
void _pseudo_code_fix_spd();

/* Getting the current pseudo code line */
int _pseudo_code_current_line();

#endif // PSEUDO_CODE_H
