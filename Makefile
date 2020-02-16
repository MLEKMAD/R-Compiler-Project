all: compilateur

compilateur: compilateur.o analyseur_lexical.o global.o analyseur_synthaxique.o symbol_table.o  pseudo_code.o
	gcc -o compilateur compilateur.o analyseur_lexical.o analyseur_synthaxique.o errors.o symbol_table.o  pseudo_code.o

compilateur.o: compilateur.c analyseur_synthaxique.h global.h analyseur_synthaxique.h symbol_table.h pseudo_code.h
	gcc -o compilateur.o -c compilateur.c

analyseur_synthaxique.o: analyseur_synthaxique.c analyseur_synthaxique.h analyseur_lexical.h global.h errors.h symbol_table.h
	gcc -std=gnu99 -o analyseur_synthaxique.o -c analyseur_synthaxique.c

pseudo_code.o: pseudo_code.h pseudo_code.c global.h
	gcc -o pseudo_code.o -c pseudo_code.c -g
symbol_table.o: symbol_table.c symbol_table.h global.h
	gcc -std=c99  -o symbol_table.o -c symbol_table.c

analyseur_lexical.o: analyseur_lexical.c global.h errors.h
	gcc -o analyseur_lexical.o -c analyseur_lexical.c

global.o: errors.c errors.h
	gcc -o errors.o -c errors.c

clean:
	rm -rf *.o *.c~ *.h~ *.r~
