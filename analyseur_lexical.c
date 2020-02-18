#include "analyseur_lexical.h"


int *i=0;
int  Car_Cour=0;
int current_line;
void Lire_Car(){
	
  Car_Cour=fgetc(Fichier);
  if(Car_Cour == '\n') current_line++;
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
    strcpy(SYM_COUR.nom,"IF_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = IF_TOKEN ;
  }
  else if((strcmp("else",chaine)==0)) {
    strcpy(SYM_COUR.nom,"else_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = ELSE_TOKEN ;
  }
  else if((strcmp("return",chaine)==0)) {
    strcpy(SYM_COUR.nom,"return_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = RETURN_TOKEN ;
  }
  else if((strcmp("repeat",chaine)==0)) {
    strcpy(SYM_COUR.nom,"REPEAT_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = REPEAT_TOKEN ;
  }
  else if((strcmp("print",chaine)==0)) {
    strcpy(SYM_COUR.nom,"PRINT_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
  SYM_COUR.CODE = PRINT_TOKEN ;
  }
  else if((strcmp("function",chaine)==0)) {
    strcpy(SYM_COUR.nom,"FUNCTION_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = FUNCTION_TOKEN ;
  }
  else if((strcmp("for",chaine)==0)) {
    strcpy(SYM_COUR.nom,"FOR_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = FOR_TOKEN ;
  }
  else if((strcmp("while",chaine)==0)) {
    strcpy(SYM_COUR.nom,"WHILE_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = WHILE_TOKEN ;
  }
  else if((strcmp("in",chaine)==0)) {
    strcpy(SYM_COUR.nom,"IN_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = IN_TOKEN ;
  }
  else if((strcmp("next",chaine)==0)) {
    strcpy(SYM_COUR.nom,"NEXT_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = NEXT_TOKEN ;
  }
  else if((strcmp("break",chaine)==0)) {
    strcpy(SYM_COUR.nom,"BREAK_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = BREAK_TOKEN ;
  }
  else if((strcmp("true",chaine)==0)) {
    strcpy(SYM_COUR.nom,"TRUE_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = TRUE_TOKEN ;
  }
  else if((strcmp("false",chaine)==0)) {
    strcpy(SYM_COUR.nom,"FALSE_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = FALSE_TOKEN ;
  }
  else if((strcmp("c",chaine)==0)) {
    strcpy(SYM_COUR.nom,"C_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = C_TOKEN ;
  }
  else if((strcmp("seq",chaine)==0)) {
    strcpy(SYM_COUR.nom,"SEQ_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = SEQ_TOKEN ;
  }
  else if((strcmp("rep",chaine)==0)) {
    strcpy(SYM_COUR.nom,"REP_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = REP_TOKEN ;
  }
  else if((strcmp("each",chaine)==0)) {
    strcpy(SYM_COUR.nom,"EACH_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = EACH_TOKEN ;
  }
  else if((strcmp("times",chaine)==0)) {
    strcpy(SYM_COUR.nom,"TIMES_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = TIMES_TOKEN ;
  }
  else if((strcmp("length",chaine)==0)) {
    strcpy(SYM_COUR.nom,"LENGTH_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = LENGTH_TOKEN ;
  }
  else if((strcmp("out",chaine)==0)) {
    strcpy(SYM_COUR.nom,"OUT_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = OUT_TOKEN ;
  }
  else if((strcmp("by",chaine)==0)) {
    strcpy(SYM_COUR.nom,"BY_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = BY_TOKEN ;
  }else if((strcmp("list",chaine)==0)) {
    strcpy(SYM_COUR.nom,"LIST_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = LIST_TOKEN ;
  }
  else if ((strcmp("TRUE",chaine)==0 || strcmp("FALSE", chaine) == 0)){
    strcpy(SYM_COUR.nom,"BOOLEAN_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
    SYM_COUR.CODE = BOOLEAN_TOKEN ;
  }
  else {
    strcpy(SYM_COUR.nom,"ID_TOKEN\n");
	strcpy(SYM_COUR.name,chaine);
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
    if((isspace(Car_Cour))
		|| (Car_Cour==')')
		|| (Car_Cour=='=')
		|| (Car_Cour==']')
		|| (Car_Cour=='{')
		|| (Car_Cour=='}')
		|| (Car_Cour==':')
		|| (Car_Cour=='+')
		|| (Car_Cour==',')
		|| (Car_Cour==-1)){
        SYM_COUR.CODE =NUM_TOKEN ;
        strcpy(SYM_COUR.nom,"NUM_TOKEN\n");
    }
    else{
        strcpy(SYM_COUR.nom,"erreur_token\n");
        SYM_COUR.CODE =ERREUR_TOKEN ;
        raise_error(UNRECOGNIZED_CHARACTER_ERROR);
		}
}
void next_sym(){
	if(isspace(Car_Cour)!=0){
		Lire_Car();
		next_sym();
	}
	else if(isalpha(Car_Cour)!=0){
		lire_mots();
	}else if(isdigit(Car_Cour)!=0){
		lire_nbr();
	}
	else
		switch(Car_Cour){
			case';':
				SYM_COUR.CODE=PV_TOKEN ;
				strcpy(SYM_COUR.nom,"PV_TOKEN\n");
				Lire_Car();
				break;
			case'.':
				SYM_COUR.CODE=POINT_TOKEN ;
				strcpy(SYM_COUR.nom,"POINT_TOKEN\n");
				Lire_Car();
				break;
            case':':
				SYM_COUR.CODE=DEUX_POINTS_TOKEN ;
				strcpy(SYM_COUR.nom,"DEUX_POINTS_TOKEN\n");
				Lire_Car();
				break;
			case'+':
				SYM_COUR.CODE=PLUS_TOKEN ;
				strcpy(SYM_COUR.nom,"PLUS_TOKEN\n");
				Lire_Car();
				break;
			case'-':
				Lire_Car();
				if(Car_Cour=='>'){
					Lire_Car();
					if(Car_Cour=='>'){
						SYM_COUR.CODE=EGAL2_RIGHT_TOKEN ;
						strcpy(SYM_COUR.nom,"EGAL2_RIGHT_TOKEN\n");
						Lire_Car();
						break;
					}else{
					SYM_COUR.CODE=EGAL1_RIGHT_TOKEN ;
					strcpy(SYM_COUR.nom,"EGAL1_RIGHT_TOKEN\n");
					break;
					}
				}else{
				SYM_COUR.CODE=MOINS_TOKEN ;
				strcpy(SYM_COUR.nom,"MOINS_TOKEN\n");
				break;
				}
			case'*':
			Lire_Car();
			if(Car_Cour=='*'){
				SYM_COUR.CODE = POWER_TOKEN;
				strcpy(SYM_COUR.nom,"POWER_TOKEN");
				break;
			}else{
				SYM_COUR.CODE= MULT_TOKEN;
				strcpy(SYM_COUR.nom,"MULT_TOKEN\n");
				Lire_Car();
				break;
			}
            case',':
				SYM_COUR.CODE= VIR_TOKEN;
				strcpy(SYM_COUR.nom,"VIR_TOKEN\n");
				Lire_Car();
				break;
            case'{':
				SYM_COUR.CODE= OCB_TOKEN;
				strcpy(SYM_COUR.nom,"OCB_TOKEN\n");
				Lire_Car();
				break;
            case'}':
				SYM_COUR.CODE= CCB_TOKEN;
				strcpy(SYM_COUR.nom,"CCB_TOKEN\n");
				Lire_Car();
				break;
            case'[':
				SYM_COUR.CODE=OSB_TOKEN ;
				strcpy(SYM_COUR.nom,"OSB_TOKEN\n");
				Lire_Car();
				break;
            case']':
				SYM_COUR.CODE= CSB_TOKEN;
				strcpy(SYM_COUR.nom,"CSB_TOKEN\n");
				Lire_Car();
				break;
			case'/':
				SYM_COUR.CODE=DIV_TOKEN ;
				strcpy(SYM_COUR.nom,"DIV_TOKEN\n");
				Lire_Car();
				break;
			case'^':
				SYM_COUR.CODE=EXPONENT_TOKEN ;
				strcpy(SYM_COUR.nom,"EXPONENT_TOKEN\n");
				Lire_Car();
				break;
			case'%':
				Lire_Car();
				if(Car_Cour =='%'){
				SYM_COUR.CODE=MODULUS_TOKEN ;
				strcpy(SYM_COUR.nom,"MODULUS_TOKEN\n");
				Lire_Car();
				break;
				}else{
					if(Car_Cour =='/'){
						Lire_Car();
						if(Car_Cour =='%'){
							SYM_COUR.CODE=INT_DIV_TOKEN ;
							strcpy(SYM_COUR.nom,"INT_DIV_TOKEN\n");
							Lire_Car();
							break;
						}
						else{
                // erreur fors syntaxe
                break;
							////erreur hors syntaxe
							break;
						}
					}
                else{
                        //erreur hors syntaxe
                        break;
							////erreur hors syntaxe
							break;
					}
				}
				//erreur hors syntaxe
				break;
			case'<':
				Lire_Car();
				if(Car_Cour == '='){
					SYM_COUR.CODE = LTE_TOKEN;
					strcpy(SYM_COUR.nom,"LTE_TOKEN\n");
					Lire_Car();
					break;
				}else{
					if(Car_Cour=='-'){
					SYM_COUR.CODE =EGAL2_LEFT_TOKEN;
					strcpy(SYM_COUR.nom,"EGAL2_LEFT_TOKEN\n");
					Lire_Car();
					break;
					}
					else{
						if(Car_Cour=='<'){
							Lire_Car();
							if(Car_Cour=='-'){
								SYM_COUR.CODE =EGAL_lEFT_TOKENT;
								strcpy(SYM_COUR.nom,"EGAL_lEFT_TOKENT\n");
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
					strcpy(SYM_COUR.nom,"INF_TOKEN\n");
					break;
					}
				}
			case'>':
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE = GTE_TOKEN ;
					strcpy(SYM_COUR.nom,"GTE_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = GT_TOKEN ;
					strcpy(SYM_COUR.nom,"GT_TOKEN\n");
					break;
				}


			case'=':
                Lire_Car();
                if(Car_Cour=='='){
                    SYM_COUR.CODE=EQ_TOKEN ;
                    strcpy(SYM_COUR.nom,"EQ_TOKEN\n");
                    Lire_Car();
                    break;
                }else{
                    SYM_COUR.CODE=EGAL_LEFT_TOKEN ;
                    strcpy(SYM_COUR.nom,"EGAL_LEFT_TOKEN =\n");
                    break;
                }
			case'!':
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE = NOT_EQ_TOKEN ;
					strcpy(SYM_COUR.nom,"NOT_EQ_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGNOT_TOKEN ;
					strcpy(SYM_COUR.nom,"LOGNOT_TOKEN\n");
					break;
				}

		 	case'&':
				Lire_Car();
				if(Car_Cour=='&'){
					SYM_COUR.CODE = ELEMENTWISE_LOGAND_TOKEN ;
					strcpy(SYM_COUR.nom,"ELEMENTWISE_LOGAND_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGAND_TOKEN ;
					strcpy(SYM_COUR.nom,"LOGAND_TOKEN\n");
					break;
				}

		 	case'|':
				Lire_Car();
				if(Car_Cour=='|'){
					SYM_COUR.CODE = ELEMENTWISE_LOGOR_TOKEN ;
					strcpy(SYM_COUR.nom,"ELEMENTWISE_LOGOR_TOKEN\n");
					Lire_Car();
					break;
				}else{
					SYM_COUR.CODE = LOGOR_TOKEN ;
					strcpy(SYM_COUR.nom,"LOGOR_TOKEN\n");
					break;
				}
            case '"':
                Lire_Car();
                while(Car_Cour!='"') {
                    Lire_Car();
                }
                strcpy(SYM_COUR.nom,"STRING_TOKEN\n");
                SYM_COUR.CODE =STRING_TOKEN ;
                Lire_Car();
				break;
            case '\'':
                Lire_Car();
                while(Car_Cour!='\'') {
                    Lire_Car();
                }
                strcpy(SYM_COUR.nom,"STRING_TOKEN\n");
                SYM_COUR.CODE = STRING_TOKEN ;
                Lire_Car();
				break;
            case '(':
				SYM_COUR.CODE=PO_TOKEN ;
				strcpy(SYM_COUR.nom,"PO_TOKEN\n");
				Lire_Car();
				break;
            case ')':
				SYM_COUR.CODE=PF_TOKEN ;
				strcpy(SYM_COUR.nom,"PF_TOKEN\n");
				Lire_Car();
				break;
			case EOF:
				SYM_COUR.CODE =FIN_TOKEN ;
				strcpy(SYM_COUR.nom,"FIN_TOKEN\n");

				 break;
			default:

				SYM_COUR.CODE =ERREUR_TOKEN ;
				raise_error(UNRECOGNIZED_CHARACTER_ERROR);
				break;
	    }
	return;
}
