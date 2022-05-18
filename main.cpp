#include"tokens.cpp"
int main()
{
	Lexico();
	FILE* tokens = fopen("compilador.txt", "r");
	char caracterToken;
	string tokenAlmacenado;
	int limiteLectura=0;
	int tokenPosicion=0;
	string tokenAnterior;
	string tokenCondicion;

	while(limiteLectura<200) {
		caracterToken = fgetc(tokens);
		if (caracterToken == '|') //encontro el delimitador
		{
			//Procede a comprobar la sintaxis
			cout<<endl<<"Token encontrado: "<<tokenAlmacenado;
			
			//cout<<"POS: "<<tokenPosicion<<endl<<endl;
			if(tokenPosicion == 0) //Mientras que dentro del primer token
			{
				if(tokenAlmacenado == "if" || (tokenAlmacenado == "while" )|| (tokenAlmacenado == "tipo") || (tokenAlmacenado == "float")|| (tokenAlmacenado == "void"))
				{
					//cout<<"En Orden, token almacenado: "<<tokenAlmacenado<<endl;
					if (tokenAlmacenado =="if"){
						tokenCondicion = "if";
						tokenAnterior = "if";
					}
					else if (tokenAlmacenado =="while"){
						tokenCondicion = "while";
						tokenAnterior = "while";
					}
					else if (tokenAlmacenado =="tipo"){
						tokenCondicion = "tipo";
						tokenAnterior = "tipo";
					}
					else if (tokenAlmacenado =="float"){
						tokenCondicion = "float";
						tokenAnterior = "float";
					}
					else if (tokenAlmacenado =="void"){
						tokenCondicion = "void";
						tokenAnterior = "void";
					}
					else if (tokenAlmacenado =="return"){
						tokenCondicion = "return";
						tokenAnterior = "return";
					}
					else if (tokenAlmacenado =="else"){
						tokenCondicion = "else";
						tokenAnterior = "else";
					}
				}
				else{
					if(tokenAlmacenado == "identificador"){ //Exista un identificador
						cout<<endl<<"[Error] Identificador no declarado"<<endl;
						break;
					}
					else if(tokenAlmacenado == "entero"){ //El primer token es entero
						cout<<endl<<"[Syntax Error] entero encontrado antes que tipo de dato"<<endl;
						break;
					}
					else if(tokenAlmacenado == "else"){ //El primer token es entero
						cout<<endl<<"[Syntax Error] else encontrado antes que if"<<endl;
						break;
					}
					else{
						cout<<endl<<"[Error] Tipo de dato no declarado"<<endl;
					}
				}
			}//if tokenPosicion == 0
			
			if (tokenAlmacenado =="if"){
					tokenCondicion = "if";
					tokenAnterior = "if";
			}
			else if (tokenAlmacenado =="while"){
					tokenCondicion = "while";
					tokenAnterior = "while";
			}
			else if (tokenAlmacenado =="tipo"){
					tokenCondicion = "tipo";
					tokenAnterior = "tipo";
			}
			else if (tokenAlmacenado =="float"){
					tokenCondicion = "float";
					tokenAnterior = "float";
			}
			else if (tokenAlmacenado =="void"){
					tokenCondicion = "void";
					tokenAnterior = "void";
			}
			else if (tokenAlmacenado =="return"){
					tokenCondicion = "return";
					tokenAnterior = "return";
			}
			else if (tokenAlmacenado =="else"){
					tokenCondicion = "else";
					tokenAnterior = "else";
			}

			if(tokenCondicion == "if"){//si el usuario esta tecleando un if
				if (tokenAlmacenado == "if"){
					//cout<<"Hay un if dentro"<<endl;
				}
				else{
					if(tokenAnterior == "if"){
						if(tokenAlmacenado == "(")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected '(' before"<<endl;
								break;
						}
					}
					if (tokenAnterior == "("){
						if(tokenAlmacenado == "identificador")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] identificador no valido"<<endl;
							break;
						}
					}
					if (tokenAnterior == "identificador"){
						if(tokenAlmacenado == "opIgualdad" || (tokenAlmacenado == ")"))
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] operador de igualdad no valido en if"<<endl;
							break;
						}
					}
					if(tokenAnterior == "opIgualdad"){
						if(tokenAlmacenado == "identificador" || (tokenAlmacenado == "entero")){
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
							
						}
						else{
								cout<<endl<<"[Syntax Error] operador no valido en if before ')'"<<endl;
								break;
						}	
					}
					if (tokenAnterior == "identificador" || (tokenAnterior == "entero")){
						if(tokenAlmacenado == ")")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] Expected ')'"<<endl;
							break;
						}
					}
					if(tokenAnterior == ")"){
						if(tokenAlmacenado == "{")
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Syntaxis Error] Expected '{' before ')'"<<endl;
								break;
						}
					}
				/*	if(tokenAnterior == "{"){ //Silenciado porque dentro de if es libre y no termina solo con {}
						if(tokenAlmacenado == "}")
						{
							cout<<"Codigo sin errores analizado exitosamente"<<endl;
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<"[Syntaxis Error] Expected '{' before ')'"<<endl;
								break;
						}
					}*/
					
				}//Fin else if tokenPosicion >0
				
			}//entra solo si la bandera de condicion es if
			
			
			if(tokenCondicion == "while"){//si el usuario esta tecleando un while
				if (tokenAlmacenado == "while"){
					//cout<<"Hay un while dentro"<<endl;
				}
				else{
					if(tokenAnterior == "while"){
						if(tokenAlmacenado == "(")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected '(' after while declaration"<<endl;
								break;
						}
					}
					if (tokenAnterior == "("){
						if(tokenAlmacenado == "identificador")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] identificador no valido"<<endl;
							break;
						}
					}
					if (tokenAnterior == "identificador"){
						if(tokenAlmacenado == "opIgualdad" || (tokenAlmacenado == ")") || (tokenAlmacenado == "opRelac") )
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] operador de igualdad no valido en while"<<endl;
							break;
						}
					}
					if(tokenAnterior == "opIgualdad"){
						if(tokenAlmacenado == "identificador" || (tokenAlmacenado == "entero")){
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
							
						}
						else{
								cout<<endl<<"[Syntax Error] operador no valido en while before ')'"<<endl;
								break;
						}	
					}
					if (tokenAnterior == "identificador" || (tokenAnterior == "entero")){
						if(tokenAlmacenado == ")")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						
						}
						else{
							cout<<endl<<"[Syntax Error] Expected ')'"<<endl;
							break;
						}
					}
					if(tokenAnterior == ")"){
						if(tokenAlmacenado == "{")
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Syntaxis Error] Expected '{' before ')'"<<endl;
								break;
						}
					}
					
				}//Fin else if tokenPosicion >0
				
			}//entra solo si la bandera de condicion es while
			
			
			if(tokenCondicion == "else"){//si el usuario esta tecleando un else
				if (tokenAlmacenado == "else"){
					if(tokenAnterior=="}"){
						tokenAnterior=tokenAlmacenado;
						goto seCumple;
						//cout<<"todo en orden"<<endl;
					}
					else{
						cout<<endl<<"[Error] Expected '}' before"<<endl;
						break;
					}
					//cout<<"Hay un else dentro"<<endl;
				}
				else{
					if(tokenAnterior == "else" || (tokenAnterior == "}")){
						if(tokenAlmacenado == "{")
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected '{' before"<<endl;
								break;
						}
					}
					
				}//Fin else if tokenPosicion >0
				
			}//entra solo si la bandera de condicion es else
			
			if(tokenCondicion == "return"){//si el usuario esta tecleando un return
				if (tokenAlmacenado == "return"){
					//cout<<"Hay un else dentro"<<endl;
				}
				else{
					if(tokenAnterior == "return"){
						if(tokenAlmacenado == "identificador"|| (tokenAlmacenado == "entero"))
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected 'identificador o entero' before"<<endl;
								break;
						}
					}
					
				}//Fin else if tokenPosicion >0
				
			}//entra solo si la bandera de condicion es return
			
			if(tokenCondicion == "tipo"){//si el usuario esta tecleando un int,float,void
				if (tokenAlmacenado == "tipo"){
					//cout<<"Hay un tipo dentro"<<endl;
				}
				else{
					if(tokenAnterior == "tipo"){
						if(tokenAlmacenado == "identificador"|| (tokenAlmacenado =="{"))
						{
							//cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected 'identificador o entrada valida' before"<<endl;
								break;
						}
					}
					if(tokenAnterior == "identificador"){
						if(tokenAlmacenado == "opIgualdad"|| (tokenAlmacenado == ";"))
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected 'opIgualdad' before"<<endl;
								break;
						}
					}
					if(tokenAnterior == "opIgualdad"){
						if(tokenAlmacenado == "identificador"|| (tokenAlmacenado =="entero"))
						{
							cout<<endl<<"Sentencia de codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<endl<<"[Error] Expected 'identificador o entero' before"<<endl;
								break;
						}
					}
					
					
				}//Fin else if tokenPosicion >0
				
			}//entra solo si la bandera de condicion es int
			
			
			
			
		seCumple:
		tokenAlmacenado="";
		tokenPosicion++;
		} //Fin de encontrar token
		else{//Sigue buscando delimitador.. token
			//printf("%c",var);
			tokenAlmacenado+=caracterToken;
			limiteLectura=limiteLectura+1;
		}
			
		
	}//Fin while buscando tokens de codigo de hasta 200 letras
	fclose(tokens);
	cout<<endl<<"Fin de compilacion";
		
    return 0;
}
