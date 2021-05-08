#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[30];
	printf("Digite o nome: \n");
	scanf("%[^\n]",nome);
	for (int i = strlen(nome); i >= 0; --i)
	{
		printf("%c", nome[i]);
	}
	printf("\n");
}