/*análisis léxico*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

char input[200];    // Almacena la cadena de entrada 
char token[20];      // Almacena la cadena que forma el símbolo de la palabra 
char ch;            // Almacena los caracteres leídos actualmente 
int p;              // input [] subíndice 
int fg;             // marca de cambio 
int num;            // Almacenar valores enteros 

// Matriz de caracteres bidimensionales, almacenando palabras clave 
char index[7][7]={"if","while","return","else","int","float", "void"};

// Declaración del método de análisis léxico
//void scaner();  

void scaner()
{
	int m=0;        // token [] subíndice 
	int n;
  
    // Filtrar espacios 
    ch=input[p++];
    while(ch==' ') ch=input[p++];
  
    // Flujo de procesamiento de palabras clave (identificador) 
    if(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' ))
    {
            while(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' )||( ch<='9' && ch>='0' ))
            {
                 token[m++] = ch;
                 ch = input[p++];
            }
            p--;
            token[m++] = '\0';
            fg = 8;

            for( n=0; n<7; n++ )
            {
                if(strcmp(token, index[n])==0)// strcmp () compara dos cadenas y devuelve 0 si son iguales 
                    {
                        fg = n+1;
                        break;
                    }
            }
    }
       
    // Flujo de procesamiento digital 
    else if(( ch<='9' && ch>='0' ))
    {
        num=0;
        while(( ch<='9' && ch>='0' ))
        {
            num = num*10+ch-'0';
            ch = input[p++];
        }
        p--;
        fg = 9;
    }
     
    // Flujo de procesamiento del delimitador del operador 
    else
        switch(ch)
        {
		    case '>':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar >= 
                {
                    fg=17;
                    token[m++]=ch;
                }
                else               // Generar > 
                {
                    fg=16;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
            case '<':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar <= 
                {
                    fg=38;
                    token[m++]=ch;
                }
                else               // Generar < 
                {
                    fg=39;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
            case '|':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='|')        // Generar ||
                {
                    fg=40;
                    token[m++]=ch;
                }
                else               // Generar | 
                {
                    fg=41;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
            case '&':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='&')        // Generar &&
                {
                    fg=42;
                    token[m++]=ch;
                }
                else               // Generar &
                {
                    fg=43;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
                 
            case '+': fg=35; token[0]=ch; token[1]='\0'; break;
            case '-': fg=10; token[0]=ch; token[1]='\0'; break;
            case '*': fg=11; token[0]=ch; token[1]='\0'; break;
            case '/': fg=12; token[0]=ch; token[1]='\0'; break;
            //case '=': fg=18; token[0]=ch; token[1]='\0'; break;
            case '=':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar == 
                {
                    fg=32;
                    token[m++]=ch;
                }
                else               // Generar = 
                {
                    fg=33;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
            case ';': fg=19; token[0]=ch; token[1]='\0'; break;
            case '(': fg=20; token[0]=ch; token[1]='\0'; break;
            case ')': fg=21; token[0]=ch; token[1]='\0'; break;
            case '{': fg=45; token[0]=ch; token[1]='\0'; break;
            case '}': fg=46; token[0]=ch; token[1]='\0'; break;
            case '$': fg=47; token[0]=ch; token[1]='\0'; break;
            
            case '#': fg=99; token[0]=ch; token[1]='\0'; break;
            // cambios
			//case '!': fg=22; token[0]=ch; token[1]='\0'; break;
			case '!':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar != 
                {
                    fg=30;
                    token[m++]=ch;
                }
                else               // Generar ! 
                {
                    fg=31;
                    p--;
                }
                token[m++] = '\0';
                break; 
            }
            case '.': fg=34; token[0]=ch; token[1]='\0'; break;
            case ',': fg=44; token[0]=ch; token[1]='\0'; break;
            default: fg=-1;
        }

}
