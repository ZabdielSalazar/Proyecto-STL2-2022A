#include <stdio.h>

enum{ASIGNACION=257,IDENTIFICADOR};

int elToken; /*global con sig. token*/
void terminal(int token){
if(elToken==token)
elToken=yylex();
else
printf("...INFO(elToken) inesperado...%d",elToken);
}
void instruccion(){
terminal(IDENTIFICADOR);
terminal(ASIGNACION);
expresion();
terminal((int)';');
}
int main(){
  /*inicia desplazamiento*/
elToken=yylex();
instruccion();
}

void termino(){
if(elToken==IDENTIFICADOR)
terminal(IDENTIFICADOR);
else if(elToken=='('){
terminal((int) '(');
expresion();
terminal((int) ')');
}else
hayError("Se esperaba un IDENTIFICADOR o '('");
}

void expresion(){
termino();
expresionP();
}
void expresionP(){
if(elToken=='+'){
terminal((int) '+');
termino();expresionP();
} /*else: corresponde a e */
}
