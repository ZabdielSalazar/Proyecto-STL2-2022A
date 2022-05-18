#include"comprobaciones.cpp"
int Lexico(){
	//Crear y abrir fichero
	FILE* fichero;
    fichero = fopen("compilador.txt", "wt");
    
    p=0;
    printf("Ingresa el codigo (Termina con '#'):\n");
    
    // leer cíclicamente en caracteres
    do {
        ch=getchar();
        input[p++] = ch;
    } while( ch!='#' );

    p=0;
    do {

        scaner();

        switch( fg )
        {
            case 8:
				//printf("( %d,%d  )", fg,num);
				printf("Identificador:0   "); 
				fputs("identificador|", fichero);
				break;
				     
            case -1:printf("input error\n"); 
            		fputs("error|", fichero);   
			break; 
			       
            default:
				//printf("( %d,%s )", fg, token);
				if (fg == 9){
					printf("Entero:1   ");
					fputs("entero|", fichero);
				}
				else if (fg == 5 || fg == 6 || fg == 7){
					printf("Tipo:4   ");
					fputs("tipo|", fichero);
				}
				else if (fg == 35 || fg == 10){
					printf("OpSuma:5   ");
					fputs("opSuma|", fichero);
				}
				else if (fg == 11 || fg == 12){
					printf("OpMul:6   ");
					fputs("opMul|", fichero);
				}
				else if (fg == 17 || fg == 16 || fg == 38 || fg == 39){
					printf("OpRelac:7   ");
					fputs("opRelac|", fichero);
				}
				else if (fg == 40){
					printf("OpOr:8   ");
					fputs("opOr|", fichero);
				}
				else if (fg == 42){
					printf("OpAnd:9   ");
					fputs("opAnd|", fichero);
				}
				else if (fg == 31){
					printf("OpNot:10   ");
					fputs("opNot|", fichero);
				}
				else if (fg == 30 || fg == 32){
					printf("OpIgualdad:11   ");
					fputs("opIgualdad|", fichero);
				}
				else if (fg == 19){
					printf(";:12   ");
					fputs(";|", fichero);
				}
				else if (fg == 44){
					printf(",:13   ");
					fputs(",|", fichero);
				}
				else if (fg == 20){
					printf("(:14   ");
					fputs("(|", fichero);
				}
				else if (fg == 21){
					printf("):15   ");
					fputs(")|", fichero);
				}
				else if (fg == 45){
					printf("{:16   ");
					fputs("{|", fichero);
				}
				else if (fg == 46){
					printf("}:17   ");
					fputs("}|", fichero);
				}
				else if (fg == 33){
					printf("=:18   ");
					fputs("=|", fichero);
				}
				else if (fg == 1){
					printf("if:19   ");
					fputs("if|", fichero);
				}
				else if (fg == 2){
					printf("while:20   ");
					fputs("while|", fichero);
				}
				else if (fg == 3){
					printf("return:21   ");
					fputs("return|", fichero);
				}
				else if (fg == 4){
					printf("else:22   ");
					fputs("else|", fichero);
				}
				else if (fg == 47){
					printf("$:23   ");
					fputs("$|", fichero);
				}
				else if (fg == 34){
					printf(".:23   ");
					fputs(".|", fichero);
				}
        }
    } while( fg != 99 );
    //cerrar fichero
    fclose(fichero);
	cout<<endl<<"Tokens Agregados."<<endl;
}
