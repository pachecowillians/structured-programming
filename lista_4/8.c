#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Pessoa{
	char nome[30], sexo[20];
	float peso, altura; 
	int cpf;
};


int main(){
	system("clear");
	#define QUANTIDADE_DE_PESSOAS 3 // constante
	struct Pessoa pessoas[QUANTIDADE_DE_PESSOAS-1]; 
	//O vetor pessoas é do tipo de dados de Registro Pessoa, com tamanho QUANTIDADE_DE_PESSOAS
	int cpf_localizador;

	for (int i = 0; i < QUANTIDADE_DE_PESSOAS-1; ++i)
	{
		__fpurge(stdin);
		printf("Digite o nome: ");
		scanf("%[^\n]", pessoas[i].nome);
		__fpurge(stdin);
		printf("Digite a altura: ");
		scanf("%f", &pessoas[i].altura);
		__fpurge(stdin);
		printf("Digite o peso: ");
		scanf("%f", &pessoas[i].peso);
		__fpurge(stdin);
		printf("Digite o cpf: ");
		scanf("%d", &pessoas[i].cpf);
		__fpurge(stdin);
		printf("Digite o sexo: ");
		scanf("%[^\n]", pessoas[i].sexo);
	}
	printf("Digite o CPF a pesquisar: ");
	scanf("%d", &cpf_localizador);	
	
	for (int i = 0; i < QUANTIDADE_DE_PESSOAS-1; ++i){
		if (pessoas[i].cpf==cpf_localizador)
		{
			printf("%s\n", pessoas[i].nome);
			printf("%s\n", pessoas[i].sexo);
			// Cálculo do IMC = peso / (altura * altura)
			printf("%.2f\n", pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura));
		}
	}
}
