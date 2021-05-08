#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char nome[30];
	float consumo, consumoMensal, precoHoje = 3.63, valor=0;

	printf("Digite o nome do posto: ");
	scanf("%[^\n]",nome);
	printf("Digite o consumo anual: ");
	scanf("%f", &consumo);

	consumoMensal = consumo/12;

	if (consumoMensal<=50000)
		valor = precoHoje*1.2;
	else
		valor = precoHoje*1.12;

	printf("O preço para o posto %s hoje será de %.4f\n", nome,valor);
}