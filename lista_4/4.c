#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void InsereChar(char s[60], char c, int indice){
	int k=0;
	char sf[50];
	for (int i = 0; i < strlen(s)+1; ++i)
	{
		if (i+1==indice)
		{
			sf[i] = c;
			k++;
		}else
			sf[i] = s[i-k];
	}	
		printf("%s\n", sf);
}


int main(){
	system("clear");
	char nome[20] = "Programacao";
	InsereChar(nome,'X',4);
	InsereChar(nome,'X',3);
	InsereChar(nome,'X',2);
}