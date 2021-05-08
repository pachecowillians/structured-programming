#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void RotinaFrases(){
	char Frase_A [90], Frase_B [90];
	printf("Digite a frase A: ");
	scanf("%[^\n]", Frase_A);
	__fpurge(stdin);
	printf("Digite a frase B: ");
	scanf("%[^\n]", Frase_B);
	__fpurge(stdin);

	if (strlen(Frase_A)>strlen(Frase_B))
		strcpy(Frase_B,Frase_A);
	else
		strcat(Frase_A, Frase_B);

	printf("Frase A: %s\n", Frase_A);
	printf("Frase B: %s\n", Frase_B);
}


int main(){
	system("clear");
	RotinaFrases();
}