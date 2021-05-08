/*Nesse c�digo de cabe�alho .h � verificado qual o sistema operacional 
est� sendo utilizado. A partir disso, � ativada ou n�o a biblioteca windows.
Independente do sistema operacional � realizada a altera��o de cores na fun��o cor, sendo:
1: branca
2: verde
3: azul
4: vermelha
Em sistemas operacionais de base Unix foi aplicado os comandos ANSI para cores, por exemplo,
\x1b[32m � o comando para a cor verde. Caso a vers�o do sistema operacional n�o suporte esses
comandos (ANSI) as cores n�o ser�o alteradas!*/

#ifndef __COR_H__
#ifdef __unix__
  //Se necess�rio incluir blibliotecas da base unix
#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h> // Ativa a biblioteca Windows

#endif
    
void cor(int cod_cor){
#ifdef OS_Windows /*Verifica se o sistema operacional detectado � Windows */
 /* Codigo Windows */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /* Cria um console para acessar os comandos de cores da biblioteca windows */
    switch (cod_cor){
	 /*Altera a cor para branca - Mistura de cores	*/
     case 1:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);        
     break;
     /*Altera a cor para verde*/
     case 2:
       SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
     break;
     /*Altera a cor para azul*/
    case 3:
       SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
     break;
     /*Altera a cor para vermelho*/
    case 4:
       SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
     break;
     /*Altera a cor para branca*/
    default:
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);        	
    break;
 	}
#else 
 /* Sistema Operacional eh de base unix */
 switch (cod_cor){
    case 1: /*Retorna a cor ao padr�o*/
     printf ("\x1b[0m");
    break;
    case 2:/*Altera a cor para verde*/
     printf ("\x1b[32m");	
    break;
     case 3:/*Altera a cor para azul*/
     printf ("\x1b[34m");	
    break;
    case 4:/*Altera a cor para vermelha*/
     printf ("\x1b[31m");	
    break;
    default:
     printf ("\x1b[0m"); /*Retorna a cor ao padr�o*/	
    break;
	}
	
 #endif 
    
}

#endif
