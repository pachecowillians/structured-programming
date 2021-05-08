#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[20];

	printf("Digite a string: ");
	__fpurge(stdin);
	scanf("%[^\n]", nome);
	for (int i = 0; i < strlen(nome); ++i)
		printf("%c", nome[i]);
	printf("\n");
	for (int i = strlen(nome); i >= 0; --i)
		printf("%c", nome[i]);
	printf("\n");
}