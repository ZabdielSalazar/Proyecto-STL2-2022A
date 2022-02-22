#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
FILE* fichero;
fichero = fopen("compilador.txt", "r");
char var;
string token;
int cont=0;
int inicial=0;

while(cont<200) {
	var = fgetc(fichero);
	if (var == '|'){
		//encontro el delimitador
		//Procede a comprobar la gramática
		cout<<"Token encontrado: "<<token<<endl;
		cout<<"id: "<<inicial<<endl<<endl;
		if(inicial == 0){
			if(token == "identificador"){
				cout<<"[Syntax Error] Identificador encontrado antes"<<endl;
				break;
			}
			else if(token == "entero"){
				cout<<"[Syntax Error] entero encontrado antes"<<endl;
				break;
			}
		} //Termina el programa con error
		
		if(token == "while"){
			//Encontro un while
			cout<<"esto es un while"<<endl;
			
			inicial=1;
		}
		if(token == "if"){
			//Encontro un if
			cout<<"esto es un if"<<endl;
			
			inicial=1;
		}
		
		
	token="";
	}
	else{//Sigue buscando delimitador
		//printf("%c",var);
		token+=var;
		cont=cont+1;
	}
		
	
}
fclose(fichero);
cout<<endl<<"FIN DE PROGRAMA";

}
