#include "analyseur_synthaxique.h"
#include "errors.h"

boolean PROG(){
	init_symbol_table();
   if(SEQ_STAT()){
	   show_symbol_table();
	   return true;}
   else return false;
}

boolean SEQ_STAT(){

    if(STAT()){
        while(STAT());
           return true;
    }return false;
}

boolean STAT(){

	if(COMPOUND_STAT()) return true ;
    else if(SIMPLE_STAT()) return true ;
    else return false;

}

boolean SIMPLE_STAT(){
	if(LIST()) return true;
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN){
		if(SYM_COUR.CODE == ID_TOKEN){

			 add_symbol(TVAR);

			delete_symbol();
		}

		next_sym();
		if(SIMPLE_EXP_END()) return true;
		if(NUM_SEQ_END()) return true;
	 	if(ASSG_OR_CALL_END()) return true;
	}
	if(REP_FUNCT()) return true;
    else if(RETURN()) return true;
    else false;

}

boolean COMPOUND_STAT(){
    if(IF_STAT()) return true ;
    else if(LOOP_STAT()) return true;
    else return false;

}

boolean LOOP_STAT(){
    if(WHILE_LOOP()) return true;
    else if(FOR_LOOP()) return true;
    else if(REPEAT_LOOP()) return true;
    else return false ;
}

boolean WHILE_LOOP(){

    if(SYM_COUR.CODE != WHILE_TOKEN) return false;

    else{

        next_sym();

        if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
        else{

            next_sym();
            if(!COND()) {printf("jxhv\n"); raise_error(COND_EXPECTED);}


			
            if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);

			next_sym();
			
		    if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);

			next_sym();

            if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED);


			
            if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
			next_sym();
			return true;
        }
    }
}

boolean FOR_LOOP(){
	
    if(SYM_COUR.CODE != FOR_TOKEN) return false;
    next_sym();
    if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
    next_sym();
    if(SYM_COUR.CODE != ID_TOKEN) raise_error(IDENTIFIER_EXPECTED_ERROR);
    next_sym();
    if(SYM_COUR.CODE != IN_TOKEN) raise_error(IN_EXPECTED_ERROR);
    next_sym();
	if(C_FUNCT()){
		if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
		next_sym();
		if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
		next_sym();
		if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED) ;
		if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
		next_sym();
		return true ;
		}
			
	else{
		if(SYM_COUR.CODE != ID_TOKEN && SYM_COUR.CODE != NUM_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
		next_sym();
		if(SYM_COUR.CODE != DEUX_POINTS_TOKEN) raise_error(DEUXPOINT_EXPECTED_ERROR);
		next_sym();
		if(SYM_COUR.CODE != ID_TOKEN && SYM_COUR.CODE != NUM_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
		next_sym();
		if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
		next_sym();
		if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
		next_sym();
		
		if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED) ;

		if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
		next_sym();
		return true ;
	}
}

boolean REPEAT_LOOP(){


    if(SYM_COUR.CODE != REPEAT_TOKEN) return false;
    next_sym();
	if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
	else{
		next_sym();
    	if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED) ;
		else{
			
			if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
			next_sym();
			return true;
		}
	}


}

boolean IF_STAT(){

    if(SYM_COUR.CODE != IF_TOKEN) return false;
    next_sym();

    if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
    next_sym();

    if(!COND()) { printf("333\n"); raise_error(COND_EXPECTED) ;}

    if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);

    next_sym();
    if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
    next_sym();


    if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED);


    if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
	next_sym();

	if(SYM_COUR.CODE == ELSE_TOKEN){
		
		do{
			next_sym();

			if(SYM_COUR.CODE == IF_TOKEN){
				next_sym();
				if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
				else{
					next_sym();
					if(!COND()){printf("in condition\n"); raise_error(COND_EXPECTED);}
					else{

						if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
						else{
							next_sym();
							if(SYM_COUR.CODE != OCB_TOKEN ) raise_error(OCB_EXPECTED_ERROR);
							else{
									next_sym();
									if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED);
									else{
										if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
										next_sym();
									}

							}
						}
					}

				}
			}
			else{
				
				if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
				else{
					if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED);
					else{
						if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
						next_sym();
						break;
					}
				}
			}
		}while(SYM_COUR.CODE == ELSE_TOKEN);
	}
	next_sym();
	return true;


}

boolean ASSG_OR_CALL_END(){
	if(ASSG()){

		return true;}

	if(CALL()){
		return true;}
	if(SIMPLE_EXP_END()){

		return true;}


	return false;
}

boolean ASSG(){
	if(SIMPLE_ASSG()) return true;
	if(FUNC_ASSG_2()) return true;
	return false;
}

boolean	SIMPLE_ASSG(){

	if(ASSOP()){

		next_sym();

		if(!SIMPLE_EXP()) raise_error(SIMPLE_EXP_EXPECTED);
		return true;

	}
	return false;
}

boolean FUNC_ASSG(){
		if(SYM_COUR.CODE != FUNCTION_TOKEN) return false;
		else{
			next_sym();
			 if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
			 else{
            next_sym();
            if(SYM_COUR.CODE != ID_TOKEN) raise_error(IDENTIFIER_EXPECTED_ERROR);
			
			else{
                next_sym();
            while(SYM_COUR.CODE == VIR_TOKEN){
                next_sym();
                if(SYM_COUR.CODE != ID_TOKEN) raise_error(IDENTIFIER_EXPECTED_ERROR);
                next_sym();
            }
            }
            if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
			else{
				next_sym();
				if(SYM_COUR.CODE != OCB_TOKEN) raise_error(OCB_EXPECTED_ERROR);
				else{
					next_sym();
					if(!SEQ_STAT()) raise_error(SEQ_STAT_EXPECTED);
					else{

						if(SYM_COUR.CODE != CCB_TOKEN) raise_error(CCB_EXPECTED_ERROR);
						return true;
					}
				}
			}
		}
	}


}

boolean CALL(){
	 if(SYM_COUR.CODE!= PO_TOKEN) return false;
	 else{
            next_sym();
            if(SYM_COUR.CODE != ID_TOKEN && SYM_COUR.CODE != NUM_TOKEN) raise_error(IDENTIFIER_EXPECTED_ERROR);
				if(SYM_COUR.CODE == ID_TOKEN){
					if(!symbol_exists()) raise_error(SYMBOL_DONT_EXIST);
				}
			else{
                next_sym();
            while(SYM_COUR.CODE== VIR_TOKEN){
                next_sym();
                if(SYM_COUR.CODE != ID_TOKEN && SYM_COUR.CODE != NUM_TOKEN) {
				raise_error(IDENTIFIER_EXPECTED_ERROR);
				}
                else{
					if(SYM_COUR.CODE == ID_TOKEN){
						if(symbol_exists() == -1) raise_error(SYMBOL_DONT_EXIST);
				}
					next_sym();}
            }
			if(SYM_COUR.CODE== PF_TOKEN) return true;
            }

		}
}

boolean COND(){


	if(REL()){



		while(SYM_COUR.CODE == ELEMENTWISE_LOGAND_TOKEN){
			next_sym();
			if(!REL()){
				raise_error(REL_EXPECTED);
				return false;
			}
			else{
				next_sym();
			}
		}
		while(SYM_COUR.CODE == ELEMENTWISE_LOGOR_TOKEN){
			next_sym();
			if(!REL()){
				raise_error(REL_EXPECTED);
				return false;
			}
			else{
				next_sym();
			}
		}

	return true;
				}
}

boolean REL(){


	if(SIMPLE_EXP()){

		if(!RELOP()) raise_error(CHARACTER_EXPECTED_ERROR);
		else{
			next_sym();
			if(!SIMPLE_EXP()) raise_error(SIMPLE_EXP_EXPECTED);
			else{
				return true;
			}
		}
	}
	return false;
}

boolean SIMPLE_EXP(){
	if(SYM_COUR.CODE == STRING_TOKEN){
		set_last_symbol_type(TCHR);
		next_sym();
		return true;}

	if(!TERM()) return false;
	else{



		//next symbol is given by TERM
		if(ADDINGOP()){

			next_sym();
			if(!TERM()) raise_error(TERM_EXPECTED);



		}


		return true;
	}
}

boolean TERM(){

	if(C_FUNCT()) return true;
	if(!FACTOR()) return false;
	else{
		//next symbol is given by FACTOR

		if(MULTIOP()){

			next_sym();
			if(!FACTOR()) raise_error(FACTOR_EXPECTED);


		}
		return true;
	}
}

boolean FACTOR(){

	if(!PRIMARY()) return false;
	else{
		next_sym();

		if(SYM_COUR.CODE == POWER_TOKEN){
			next_sym();
			if(!PRIMARY()) raise_error(ID_OR_NUM_EXPECTED_ERROR);
		}
		return true;
	}
}

boolean PRIMARY(){


	if(SYM_COUR.CODE == NUM_TOKEN){
		set_last_symbol_type(TINT);
		
		return true;}
	if(SYM_COUR.CODE == ID_TOKEN) return true;
	return false;
}
boolean RELOP(){


    switch(SYM_COUR.CODE){
        case LT_TOKEN:
        case GT_TOKEN:
        case LTE_TOKEN:
        case GTE_TOKEN:
        case EQ_TOKEN:
        case NOT_EQ_TOKEN: return true;
        default: return false;

    }

}

boolean ASSOP(){
	if(SYM_COUR.CODE== EGAL_LEFT_TOKEN) return true;

    else if(SYM_COUR.CODE== EGAL_lEFT_TOKENT) return true;
    else{return false;}
}

boolean ADDINGOP(){


	if(SYM_COUR.CODE == PLUS_TOKEN) return true;
	if(SYM_COUR.CODE == MOINS_TOKEN) return true;
	return false;
}

boolean MULTIOP(){
	if(SYM_COUR.CODE == MULT_TOKEN) return true;
	if(SYM_COUR.CODE == DIV_TOKEN) return true;
	if(SYM_COUR.CODE == INT_DIV_TOKEN) return true;
	if(SYM_COUR.CODE == MODULUS_TOKEN) return true;
	return false;
}

boolean RETURN(){
	if(SYM_COUR.CODE != RETURN_TOKEN) return false;
	else{
		next_sym();
		if(!PRIMARY()) raise_error(ID_OR_NUM_EXPECTED_ERROR);
		else{
			return true;
		}
	}
}

boolean ASSG_OR_FUNC(){

	if(SYM_COUR.CODE != ID_TOKEN) return false;
	else{
		add_symbol(TVAR);

		next_sym();

		if(!ASSG_OR_CALL_END()) raise_error(ASSIGNEMENT_OR_PROCEDURE_CALL_END_STATEMENT_ERROR);
		else{
			//next_sym();
			return true;
		}
	}
}

boolean SIMPLE_EXP_END(){
		if(ADDINGOP()){

			next_sym();
			if(!SIMPLE_EXP()) raise_error(SIMPLE_EXP_EXPECTED);
			else{
				return true;
			}
		}
		if(MULTIOP()){
			next_sym();
			if(!SIMPLE_EXP()) raise_error(SIMPLE_EXP_EXPECTED);
			else{
				return true;
			}
		}
		return false;
}
boolean FUNC_ASSG_2(){
	if(SYM_COUR.CODE != EGAL2_LEFT_TOKEN) return false;
	else{
		next_sym();
		if(!FUNC_ASSG_3()) raise_error(ASSIGNEMENT_OR_PROCEDURE_CALL_END_STATEMENT_ERROR);
		return true;
	}
}
boolean FUNC_ASSG_3(){
	if(FUNC_ASSG()) return true;
	if(SIMPLE_EXP()) return true;
	return false;
}


boolean REP_FUNCT(){

	if( SYM_COUR.CODE != REP_TOKEN) return false;
	else{
	next_sym();
	if( SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
	next_sym();
	if(!VECT()) raise_error(VECT_EXPECTED);
	next_sym();// check this one
	if(SYM_COUR.CODE != VIR_TOKEN) return false ;
	next_sym();
	if(!VECT_FUNCT()) raise_error(VECT_FUNCT_EXPECTED) ;
	next_sym();
	if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
	next_sym();
	return true;}

}//verified


boolean VECT(){

	if(!C_FUNCT() && !SEQ_FUNCT() && !NUM_SEQ()) return false;

	return true;
}

boolean SEQ_FUNCT(){
	if(SYM_COUR.CODE != SEQ_TOKEN) return false ;
	next_sym();
	if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
	next_sym();
	if(!ARG_SEQ()) raise_error(ARG_SEQ_EXPECTED);
	if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
	return true;
}

boolean ARG_SEQ(){
	if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) return false;
	next_sym();
	if(SYM_COUR.CODE ==VIR_TOKEN){
		next_sym();
		if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
		else{
			next_sym();
			if(SYM_COUR.CODE == VIR_TOKEN){
				next_sym();
				if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
				next_sym();
			}
			}
	}

	return true ;

}
boolean NUM_SEQ(){
    if(SYM_COUR.CODE != NUM_TOKEN ) return false ;
    next_sym();
    if(SYM_COUR.CODE != DEUX_POINTS_TOKEN) raise_error(DEUXPOINT_EXPECTED_ERROR);
    next_sym();
    if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
    return true ;

}
boolean NUM_SEQ_END(){

    if(SYM_COUR.CODE != DEUX_POINTS_TOKEN) return false;
    next_sym();
    if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
    return true ;

}
boolean C_FUNCT(){

    if(SYM_COUR.CODE != C_TOKEN) return false;


    next_sym();
    if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
    next_sym();
    if(!SameDataType()) raise_error(CHARACTER_EXPECTED_ERROR);

    if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
    next_sym();//pay attention
	return true;
}

boolean SameDataType(){
	if(!NUM_ARG() && !CHAR_ARG() && !BOOLEAN_ARG() && !C_FUNCT() ) return false;
	return true;

}
boolean NUM_ARG(){
	if(SYM_COUR.CODE == NUM_TOKEN ){
		next_sym();
		while(SYM_COUR.CODE == VIR_TOKEN){
			next_sym();
			if(SYM_COUR.CODE != NUM_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
			next_sym();
		}
		return true  ;
}
}
boolean CHAR_ARG(){
	if(SYM_COUR.CODE == STRING_TOKEN) {
		next_sym();
		while(SYM_COUR.CODE == VIR_TOKEN){
			next_sym();
			if(SYM_COUR.CODE != STRING_TOKEN) raise_error(STRING_TOKEN_EXPECTED);
			next_sym();
		}
	return true ;
}}
 boolean BOOLEAN_ARG(){
 	if(SYM_COUR.CODE == BOOLEAN_TOKEN){
 		next_sym();
 		while(SYM_COUR.CODE == VIR_TOKEN){
 			next_sym();
 			if(SYM_COUR.CODE != BOOLEAN_TOKEN) raise_error(BOOLEAN_EXPECTED);
 			next_sym();
 		}return true ;
 	}
}

boolean VECT_FUNCT(){
	if(!TIMES_FUNCT() && !EACH_FUNCT() && !LENGTH_FUNCT() && !BY_FUNCT()) return false;
	return true;

}
boolean TIMES_FUNCT(){


 	if(SYM_COUR.CODE != TIMES_TOKEN) return false;
 	next_sym();
 	if(SYM_COUR.CODE != EGAL_LEFT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
 	next_sym();
 	if((SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) && !C_FUNCT() ) raise_error(CHARACTER_EXPECTED_ERROR);
 	return true;

}
boolean EACH_FUNCT(){
	if(SYM_COUR.CODE != EACH_TOKEN) return false;
	next_sym();
	if(SYM_COUR.CODE != EGAL_LEFT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
	next_sym();
	if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
	return true ;
}
 boolean BY_FUNCT(){

 	if(SYM_COUR.CODE != BY_TOKEN) return false ;
 	next_sym();
 	if(SYM_COUR.CODE != EGAL_LEFT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
 	next_sym();
 	if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
 	return true ;

 }
 boolean LENGTH_FUNCT(){
 	if(SYM_COUR.CODE != LENGTH_TOKEN) return false;
 	next_sym();
 	if(SYM_COUR.CODE != POINT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
 	next_sym();
 	if(SYM_COUR.CODE != OUT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
 	next_sym();
 	if(SYM_COUR.CODE != EGAL_LEFT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
 	next_sym();
 	if(SYM_COUR.CODE != NUM_TOKEN && SYM_COUR.CODE != ID_TOKEN) raise_error(ID_OR_NUM_EXPECTED_ERROR);
 	return true ;

 }

boolean LIST(){
	if(SYM_COUR.CODE != LIST_TOKEN) return false;
	next_sym();
	if(SYM_COUR.CODE != PO_TOKEN) raise_error(PO_EXPECTED_ERROR);
	next_sym();
	if(!ARGS()) raise_error(CHARACTER_EXPECTED_ERROR);
	
	if(SYM_COUR.CODE != PF_TOKEN) raise_error(PF_EXPECTED_ERROR);
	next_sym();
	
	return true;
}
boolean ARGS(){
	if(SYM_COUR.CODE == STRING_TOKEN) {
		next_sym();
		if(SYM_COUR.CODE != EGAL_LEFT_TOKEN) raise_error(CHARACTER_EXPECTED_ERROR);
		next_sym();
		if(!ARGUMENT()) raise_error(CHARACTER_EXPECTED_ERROR);
		return true;
	}

	if(!ARGUMENT()) raise_error(CHARACTER_EXPECTED_ERROR);
	return true;

}
boolean ARGUMENT(){
	if(!ARGM()) return false;
	next_sym();
	if(SYM_COUR.CODE == VIR_TOKEN){
		next_sym();
		if(!ARGM()) raise_error(CHARACTER_EXPECTED_ERROR);
		return true;
	}
	return true ;
}
boolean ARGM(){
	if(SYM_COUR.CODE == NUM_TOKEN  || SYM_COUR.CODE == ID_TOKEN){
		next_sym();
		if(NUM_SEQ_END()){
		return true ;
		}
		return true;
	}
	else if(SYM_COUR.CODE != STRING_TOKEN && !C_FUNCT() && !REP_FUNCT() && !SEQ_FUNCT() && !NUM_SEQ() ) raise_error(ARGUMENT_ERROR);
	return true ;


}