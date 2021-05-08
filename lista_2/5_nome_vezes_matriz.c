#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[20];
	printf("Digite o nome: ");
	gets(nome);
	for (int i = 0; i <= strlen(nome); ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("%s ", nome);
		}
		printf("\n");
	}
}