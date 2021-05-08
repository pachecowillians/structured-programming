#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Pessoa{
	char nome[30], sexo[20];
	float peso, altura; 
	int cpf;
};

struct Pessoa * mais(struct Pessoa *p, int quantidadeInicial, int *adicionalRetorna){
	char resp[10];
	int adicional;
	do{
		printf("Quer alocar mais pessoas? ");
		__fpurge(stdin);
		scanf("%[^\n]", resp);
		if (strcmp(resp,"sim")==0)
		{
			printf("Deseja adicionar mais quantas pessoas? ");
			__fpurge(stdin);
			scanf("%d", &adicional);

			p = realloc(p,(quantidadeInicial+adicional)*sizeof(struct Pessoa));
			quantidadeInicial += adicional;

			for (int i = quantidadeInicial-adicional; i < quantidadeInicial; ++i)
			{
				__fpurge(stdin);
				printf("Digite o nome: ");
				scanf("%[^\n]", p[i].nome);
				__fpurge(stdin);
				printf("Digite a altura: ");
				scanf("%f", &p[i].altura);
				__fpurge(stdin);
				printf("Digite o peso: ");
				scanf("%f", &p[i].peso);
				__fpurge(stdin);
				printf("Digite o cpf: ");
				scanf("%d", &p[i].cpf);
				__fpurge(stdin);
				printf("Digite o sexo: ");
				scanf("%[^\n]", p[i].sexo);
			}
		}
		//para não dar double free, apenas apliquei o free quando acabei de usar o código pois a função ja altera direto o vetor que ela recebe por parâmetro.
	}while(strcmp(resp,"sim")==0);	
	*adicionalRetorna = quantidadeInicial;
	return p;
}

int main(){
	system("clear");
	#define QUANTIDADE_DE_PESSOAS 3 // constante
	struct Pessoa *pessoas;
	int *padicional, total=0;
	padicional = &total;
	pessoas = malloc((QUANTIDADE_DE_PESSOAS-1)*sizeof(struct Pessoa));

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
	__fpurge(stdin);
	pessoas = mais(pessoas, (QUANTIDADE_DE_PESSOAS-1), padicional);
	__fpurge(stdin);
	printf("Digite o CPF a pesquisar: ");
	scanf("%d", &cpf_localizador);	
	
	for (int i = 0; i < total; ++i){
		if (pessoas[i].cpf==cpf_localizador)
		{
			printf("%s\n", pessoas[i].nome);
			printf("%s\n", pessoas[i].sexo);
			// Cálculo do IMC = peso / (altura * altura)
			printf("%.2f\n", pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura));
		}
	}
	free(pessoas);
}
