#include "lexical.h"

void Lire_Car(){
    Car_Cour=fgetc(Fichier);
}
void Erreur(Erreurs ERR){
int ind_err=ERR;
printf( "Erreur numero %d \t %s \n", ind_err, MES_ERR[ind_err].mes);
}
void lire_mots(){
	char chaine[50];
	int i=0;
	while(isdigit(Car_Cour) || isalpha(Car_Cour)){
		chaine[i]=Car_Cour;
		Lire_Car();
		i=i+1;
	}
	chaine[i]='\0';
	if((strcmp("if",chaine)==0)) {
    printf("IF_TOKEN\n");
    SYM_COUR.CODE = IF_TOKEN ;
  }
  else if((strcmp("else",chaine)==0)) {
    printf("else_TOKEN\n");
    SYM_COUR.CODE = ELSE_TOKEN ;
  }
  else if((strcmp("ifelse",chaine)==0)) {
    printf("IFELSE_TOKEN\n");
    SYM_COUR.CODE = IFELSE_TOKEN ;
  }
  else if((strcmp("repeat",chaine)==0)) {
    printf("REPEAT_TOKEN\n");
    SYM_COUR.CODE = REPEAT_TOKEN ;
  }
  else if((strcmp("print",chaine)==0)) {
    printf("PRINT_TOKEN\n");
  SYM_COUR.CODE = PRINT_TOKEN ;
  }
  else if((strcmp("function",chaine)==0)) {
    printf("FUNCTION_TOKEN\n");
    SYM_COUR.CODE = FUNCTION_TOKEN ;
  }
  else if((strcmp("for",chaine)==0)) {
    printf("FOR_TOKEN\n");
    SYM_COUR.CODE = FOR_TOKEN ;
  }
  else if((strcmp("while",chaine)==0)) {
    printf("WHILE_TOKEN\n");
    SYM_COUR.CODE = WHILE_TOKEN ;
  }
  else if((strcmp("in",chaine)==0)) {
    printf("IN_TOKEN\n");
    SYM_COUR.CODE = IN_TOKEN ;
  }
  else if((strcmp("next",chaine)==0)) {
    printf("NEXT_TOKEN\n");
    SYM_COUR.CODE = NEXT_TOKEN ;
  }
  else if((strcmp("break",chaine)==0)) {
    printf("BREAK_TOKEN\n");
    SYM_COUR.CODE = BREAK_TOKEN ;
  }
  else if((strcmp("true",chaine)==0)) {
    printf("TRUE_TOKEN\n");
    SYM_COUR.CODE = TRUE_TOKEN ;
  }
  else if((strcmp("false",chaine)==0)) {
    printf("FALSE_TOKEN\n");
    SYM_COUR.CODE = FALSE_TOKEN ;
  }
  else if((strcmp("null",chaine)==0)) {
    printf("NULL_TOKEN\n");
    SYM_COUR.CODE = NULL_TOKEN ;
  }
  else {
    printf("ID_TOKEN\n");
    SYM_COUR.CODE = ID_TOKEN ;
  }
}
void lire_nbr(){
	char chaine[50];
	int i=0;
	while(isdigit(Car_Cour)){
		chaine[i]=Car_Cour;
		Lire_Car();
		i=i+1;
	}
    if((isspace(Car_Cour))|| (Car_Cour=='(' )||( Car_Cour==')') || (Car_Cour=='=') ){
        SYM_COUR.CODE =NUM_TOKEN ;
        printf("NUM_TOKEN\n");
    }
    else{
        printf("erreur_token\n");
        SYM_COUR.CODE =ERREUR_TOKEN ;
        Erreur(ERR_CAR_INC);
		}
}
void next_sym(){
	if(isspace(Car_Cour)!=0){
		Lire_Car();
	}
	else if(isalpha(Car_Cour)!=0){
		lire_mots();
	}else if(isdigit(Car_Cour)!=0){
		lire_nbr();
	}else
		switch(Car_Cour){
			case';':
				SYM_COUR.CODE=PV_TOKEN ;
				printf("pv_token\n");
				Lire_Car();
				break;
			case'.':
				SYM_COUR.CODE=POINT_TOKEN ;
				printf("POINT_TOKEN\n");
				Lire_Car();
				break;
			case'+':
				SYM_COUR.CODE=PLUS_TOKEN ;
				printf("PLUS_TOKEN\n");
				Lire_Car();
				break;
			case'-':
				Lire_Car();
				if(Car_Cour='>'){
					Lire_Car();
					if(Car_Cour=='>'){
						SYM_COUR.CODE=EGAL2_RIGHT_TOKEN ;
						printf("EGAL2_RIGHT_TOKEN\n");
						Lire_Car();
						break;
					}else{
					SYM_COUR.CODE=EGAL1_RIGHT_TOKEN ;
					printf("EGAL1_RIGHT_TOKEN\n");
					Lire_Car();
					break;
					}
				}else{
				SYM_COUR.CODE=MOINS_TOKEN ;
				printf("MOINS_TOKEN\n");
				Lire_Car();
				break;
				}

			case'*':
				SYM_COUR.CODE= MULT_TOKEN;
				printf("MULT_TOKEN\n");
				Lire_Car();
				break;
            case',':
				SYM_COUR.CODE= VIR_TOKEN;
				printf("VIR_TOKEN\n");
				Lire_Car();
				break;
            case'{':
				SYM_COUR.CODE= OCB_TOKEN;
				printf("OCB_TOKEN\n");
				Lire_Car();
				break;
            case'}':
				SYM_COUR.CODE= CCB_TOKEN;
				printf("CCB_TOKEN\n");
				Lire_Car();
				break;
            case'[':
				SYM_COUR.CODE=OSB_TOKEN ;
				printf("OSB_TOKEN\n");
				Lire_Car();
				break;
            case']':
				SYM_COUR.CODE= CSB_TOKEN;
				printf("CSB_TOKEN\n");
				Lire_Car();
				break;
			case'/':
				SYM_COUR.CODE=DIV_TOKEN ;
				printf("DIV_TOKEN\n");
				Lire_Car();
				break;
			case'^':
				SYM_COUR.CODE=EXPONENT_TOKEN ;
				printf("EXPONENT_TOKEN\n");
				Lire_Car();
				break;
			case'%':
				Lire_Car();
				if(Car_Cour=='%'){
				SYM_COUR.CODE=MODULUS_TOKEN ;
				printf("MODULUS_TOKEN\n");
				Lire_Car();
				break;
				}
				else{
					if(Car_Cour=='/'){
						Lire_Car();
						if(Car_Cour=='%'){
							SYM_COUR.CODE=INT_DIV_TOKEN ;
							printf("INT_DIV_TOKEN\n");
							Lire_Car();
							break;
						}
						else{
							////erreur hors syntaxe
							break;
						}
					}
					else{
							////erreur hors syntaxe
							break;
					}
				}
				////erreur hors syntaxe
				break;
			case'<':
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE = LTE_TOKEN;
					printf("LTE_TOKEN\n");
					Lire_Car();
					break;
				}else{
					if(Car_Cour='-'){
					SYM_COUR.CODE =EGAL2_LEFT_TOKEN;
					printf("EGAL2_LEFT_TOKEN\n");
					Lire_Car();
					break;
					}
					else{
						if(Car_Cour='<'){
							Lire_Car();
							if(Car_Cour='-'){
								SYM_COUR.CODE =EGAL_lEFT_TOKENT;
								printf("EGAL_lEFT_TOKENT\n");
								Lire_Car();
								break;
							}
							else{
								//erreur syntaxe
								break;
							}
						}else{
							//erreur syntaxe
							break;
						}
					SYM_COUR.CODE =LT_TOKEN;
					printf("INF_TOKEN\n");
					Lire_Car();
					break;
					}
				}
			case'>':
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE = GTE_TOKEN ;
					printf("GTE_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = GT_TOKEN ;
					printf("GT_TOKEN\n");
					Lire_Car();
					break;
				}


			case'=':
			Lire_Car();
			if(Car_Cour=='='){
				SYM_COUR.CODE=EQ_TOKEN ;
				printf("EQ_TOKEN\n");
				Lire_Car();
				break;
			}else{
				SYM_COUR.CODE=EGAL_LEFT_TOKEN ;
				printf("EGAL_LEFT_TOKEN =\n");
				Lire_Car();
				break;
			}
			case'!':
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE = NOT_EQ_TOKEN ;
					printf("NOT_EQ_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGNOT_TOKEN ;
					printf("LOGNOT_TOKEN\n");
					Lire_Car();
					break;
				}

		 	case'&':
				Lire_Car();
				if(Car_Cour=='&'){
					SYM_COUR.CODE = ELEMENTWISE_LOGAND_TOKEN ;
					printf("ELEMENTWISE_LOGAND_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGAND_TOKEN ;
					printf("LOGAND_TOKEN\n");
					Lire_Car();
					break;
				}
		 	case'|':
				Lire_Car();
				if(Car_Cour=='|'){
					SYM_COUR.CODE = ELEMENTWISE_LOGOR_TOKEN ;
					printf("ELEMENTWISE_LOGOR_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGOR_TOKEN ;
					printf("LOGOR_TOKEN\n");
					Lire_Car();
					break;
				}
            case '(':
				SYM_COUR.CODE=PO_TOKEN ;
				printf("PO_TOKEN\n");
				Lire_Car();
				break;
            case ')':
				SYM_COUR.CODE=PF_TOKEN ;
				printf("PF_TOKEN\n");
				Lire_Car();
				break;
			case EOF:
				SYM_COUR.CODE =FIN_TOKEN ;printf("FIN_TOKEN\n"); lire_nbr();break;
			default:
				SYM_COUR.CODE =ERREUR_TOKEN ;
				Erreur(ERR_CAR_INC);
				break;
	    }
	return;
}

































