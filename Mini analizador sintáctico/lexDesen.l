enum{ASIGNACION=257,IDENTIFICADOR};
%{
#include <stdio.h>
#include "tokens.h"
extern char yytext[]; /*ó extern char *yytext*/
%}
/*EXPRESIONES REGULARES*/
separador [\t \n]+ /*tabs,blancos*/
letra [a-zA-Z]
digito [0-9]
identificador {letra}({letra}|{digito})*
%%
{separador} {/*me los como*/}
":=" {return(ASIGNACION);}
{identificador} {return(IDENTIFICADOR);}
. {return(yytext[0]);}
%%
/* no hay funciones de usuario */
