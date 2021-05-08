#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	char nome[30], endereco[50], telefone[30];
	int idade;
	printf("Digite seu nome: ");
	scanf("%[^\n]", nome);
	printf("Digite seu endereço: ");
	scanf("%s", endereco);
	printf("Digite seu telefone: ");
	scanf("%s", telefone);
	printf("Digite sua idade: ");
	scanf("%d", &idade);

	printf("%s tem %d anos, mora em %s e o telefone é %s\n",nome, idade, endereco, telefone );
	return 0;
}