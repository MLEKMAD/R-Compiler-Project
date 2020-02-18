#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H


#include "analyseur_lexical.h"
#include "symbol_table.h"

boolean PROG();
boolean SEQ_STAT();//gives next symbol
boolean STAT();//gives next symbol
boolean SIMPLE_STAT();
boolean COMPOUND_STAT();
boolean LOOP_STAT();
boolean WHILE_LOOP();
boolean FOR_LOOP();
boolean REPEAT_LOOP();
boolean IF_STAT();//gives next symbol
boolean PRIMARY();
boolean FACTOR();//gives next symbol
boolean TERM();//gives next symbol
boolean SIMPLE_EXP();//gives next symbol
boolean REL();
boolean ASSG_OR_CALL_END();
boolean ASSG();
boolean	SIMPLE_ASSG();
boolean FUNC_ASSG();
boolean CALL();
boolean COND();
boolean RELOP();
boolean ASSOP();
boolean ADDINGOP();
boolean MULTIOP();
boolean RETURN();
boolean ASSG_OR_FUNC();
boolean SIMPLE_EXP_END();
boolean FUNC_ASSG_3();
boolean FUNC_ASSG_2();
boolean SEQ_FUNCT();
boolean VECT_FUNCT();
boolean VECT();
boolean C_FUNCT();
boolean SameDataType();
boolean NUM_ARG();
boolean CHAR_ARG();
boolean BOOLEAN_ARG();
boolean EACH_FUNCT();
boolean BY_FUNCT();
boolean LENGTH_FUNCT();
boolean ARG_SEQ();
boolean TIMES_FUNCT();
boolean NUM_SEQ();
boolean REP_FUNCT();
boolean NUM_SEQ_END();
boolean LIST();
boolean ARGS();
boolean ARGUMENT();
boolean ARGM();
boolean PRINT();

#endif
