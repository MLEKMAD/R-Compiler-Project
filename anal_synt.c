#include "lexical.h"


boolean prog(){
    if(expr()){
        while(expr());
        return true;
    }
    return false;
}

boolean expr(){
    if(function_call()) return true;
    if(operation()) return true;
    if(index_coonsturction()) return true;
    if(compound_expresion()) return true;
    if(flow_control()) return true;
    if(function_def()) return true;
    return false;
}

boolean function_call(){
    if(function_reference()){
        next_sym();
        if(Token == PO_TOKEN){
            next_sym();
            if(arg()){
                next_sym();
                while(Token == VIR_TOKEN){
                    next_sym();
                    if(!arg()) return false;
                    next_sym();
                }
            }
            if(Token == PF_TOKEN) return true;

        }
    }

    return false;

}

boolean function_def(){
    if(function_reference()){
        next_sym();
        while(Token == DOT_TOKEN){
            next_sym();
            if(Token != ID_TOKEN) return false;
            next_sym();
        }
        if(Token == PO_TOKEN){
            next_sym();
            if(arglist()){
                next_sym();
                if(Token == PF_TOKEN){
                    next_sym();
                    if(Token == OCB_TOKEN){
                        do{
                            if(!expr()) return false;
                            next_sym();
                        }while(expr());
                        if(Token == CCB_TOKEN) return true;
                    }

                }

            }




        }
    }
    return false;
}

boolean index_coonsturction(){
    if(Token == ID_TOKEN){
        next_sym();
        if(Token == OSB_TOKEN){
            if(arglist()){
                if(Token == CSB_TOKEN) return true;
            }
        }
    }
    if(Token == ID_TOKEN){
        next_sym();
        if(Token == OSB_TOKEN){
            if(Token == OSB_TOKEN){
                if(arglist()){
                    if(Token == CSB_TOKEN) {
                        if(Token == CSB_TOKEN) return true;
                    }
                }
            }
        }
    }
    return false;

}

boolean compound_expresion(){
    if(Token == OCB_TOKEN){
        next_sym();
        if(expr()){
            next_sym();
            while(Token == PV_TOKEN){
                next_sym();
                if(!expr()) return false;
                next_sym();
            }

            if(Token == CCB_TOKEN) return true;
        }
    }
    return false;

}

boolean flow_control(){
    if(if_stmt()) return true;
    if(if_else_stmt()) return true;
    if(while_stmt()) return true;
    if(repeat_stmt()) return true;
    if(for_stmt()) return true;
    return false;
}

boolean if_stmt(){
    if(token == IF_TOKEN){
        next_sym();
        if(token == PO_TOKEN){
            next_sym();
            if(cond()){
                if(token == PF_TOKEN){
                    next_sym();
                    if(expr()) return true;

                }
            }
        }
    }
    return false;
}
boolean if_else_stmt(){
    if(token == IF_TOKEN){
        next_sym();
        if(token == PO_TOKEN){
            next_sym();
            if(cond()){
                if(token == PF_TOKEN){
                    next_sym();
                    if(expr()){
                        next_sym();
                        if(Token == ELSE_TOKEN){
                            if(expr()) return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}

boolean while_stmt(){
    if(token == WHILE_TOKEN){
        next_sym();
        if(token == PO_TOKEN){
            next_sym();
            if(expr()){
                next_sym();
                if(token == PF_TOKEN){
                    next_sym();
                    if(stmt()) return true;
                }
            }
        }
    }
}

boolean repeat_stmt(){
    if(Token == REPEAT_TOKEN){
        if(expr()) return true;
    }
    return false;
}

boolean for_stmt(){
    if(Token == FOR_TOKEN){
        next_sym();
        if(Token == PO_TOKEN){
            next_sym();
            if(Token == IN_TOKEN){
                next_sym();
                if(list()){
                    next_sym();
                    if(Token == PF_TOKEN){
                        next_sym();
                        if(expr()) return true;
                    }
                }
            }
        }
    }
    return false;
}

boolean function_reference(){
    if(Token == ID_TOKEN) return true;
    if(Token == STRING_TOKEN) return true;
    if(expr()) return true;
}

boolean operation(){
    if(Token == MOINS_TOKEN){
        next_sym();
        if(expr()) return true;
    }
    if(Token == LOGNOT_TOKEN){
        next_sym();
        if(expr()) return true;
    }
    if(expr()){
        next_sym();
        if(op()){
            next_sym();
            if(expr()) return true;
        }
    }
    return false;
}

boolean list(){
    if(vector()) return true;
    if(Token == ID_TOKEN) return true;
    if(Token == PO_TOKEN){
        next_sym();
        if(item()){
            next_sym();
            while(Token == VIR_TOKEN){
                next_sym();
                if(!item()) return false;
                next_sym();
            }
        }
        if(Token == PF_TOKEN) return true;

    }


    return false;

}

boolean vector(){
    if(Token == NUM_TOKEN || Token == ID_TOKEN){
        next_sym();
        if(Token == DEUX_POINTS_TOKEN){
            if(Token == NUM_TOKEN || Token == ID_TOKEN) return true;
        }
    }
    return false;
}

boolean logical_op(){
    if(Token == LOGAND_TOKEN) return true;
    if(Token == LOGOR_TOKEN) return true;
    else
        return false;

}
boolean assgop (){
    if(Token == EGAL_LEFT_TOKENR) return true;
    else if(Token == EGAL2_LEFT_TOKEN) return true;
    else if(Token == EGAL_lEFT_TOKENT) return true;
    else{return false;}
}
boolean binop(){
    switch(token){
        case PLUS_TOKEN:
        case MOINS_TOKEN:
        case MULT_TOKEN:
        case DIV_TOKEN:return true;
        default: return false;
    }
}
boolean relop(){
    switch(token){
        case LT_TOKEN:
        case GT_TOKEN:
        case LTE_TOKEN:
        case GTE_TOKEN:
        case EQ_TOKE:
        case NOT_EQ_TOKEN:return true;
        default: return false;

    }

}
//String_token makaynach
boolean item(){
    if(Token == ID_TOKEN) return true;
    else if(Token == STRING_TOKEN) return true;//String_NUM n'existe paas
    else if(Token == NUM_TOKEN) return true;
    else return false ;
}

boolean arg (){
    if(Token == ID_TOKEN){
        Next_Sym();
        if(Token == EGAL_LEFT_TOKENR){
            Next_Sym();
            if(expr()){
                return true;
            }
        }
    }
    else if(item()){
        return true;
    }
    else if(Token == POINT_TOKEN){
        Next_Sym();
        if(Token == POINT_TOKEN){
            Next_Sym();
            if(Token == POINT_TOKEN){
                Next_Sym();
                if(Token == ELEMENTWISE_LOGOR_TOKEN){
                    Next_Sym();
                    if(Token == POINT_TOKEN){
                        Next_Sym();
                        if(Token == POINT_TOKEN){
                            Next_Sym();
                            if(Token == NUM_TOKEN){
                                Next_Sym();
                                if(Token == ELEMENTWISE_LOGOR_TOKEN){
                                    Next_Sym();
                                    if(Token == POINT){
                                        Next_Sym();
                                        if(Token == POINT_TOKEN){
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(){

    }


    else{
        return false;
    }

}

boolean arglist() {
    if (arg()) {
        Next_Sym();
        while (Token == VIR_TOKEN) {
            Next_Sym();
            if (!arg()) return false;
            Next_Sym();
        }
        if (Token == PF_TOKEN) return true;
    }
    return false;
}


boolean op(){
    if(binop()){
        return true;
    }
    else if(relop()){
        return true;
    }
    else if(assgop){
        return true;
    }
    else if(logical_op()){
        return true;
    }
    else if(Token == DEUX_POINTS_TOKEN){
        return true;
        Next_Sym();
        if(Token==DEUX_POINTS_TOKEN){
            return true;
        }else{
            break;
        }






    }
}


