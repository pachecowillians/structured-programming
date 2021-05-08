#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct{
	int dia, mes, ano;
}data;

typedef struct {
	char nome[80], endereco[100];
	int cep;
	data dt_nasc;
} Pessoa;

void imprimir(Pessoa *p, int n){
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("Pessoa: %s\n", p[i].nome);
		printf("Endereço: %s\n", p[i].endereco);
		printf("CEP: %d\n", p[i].cep);
		printf("Data: %d/%d/%d\n\n", p[i].dt_nasc.dia, p[i].dt_nasc.mes, p[i].dt_nasc.ano);
	}
}

void ordenar(Pessoa *p, int n){
	Pessoa aux;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (strcmp(p[i].nome,p[j].nome)<0)
			{
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
		}
	}
}

int main(){
	system("clear");
	Pessoa *p;
	int n;
	printf("Digite o n:");
	scanf("%d", &n);
	p = malloc(n*sizeof(Pessoa));
	for (int i = 0; i < n; ++i)
	{
		system("clear");
		__fpurge(stdin);
		printf("Digite o nome: ");
		scanf("%[^\n]", p[i].nome);
		__fpurge(stdin);
		printf("Digite o endereço: ");
		scanf("%[^\n]", p[i].endereco);
		__fpurge(stdin);
		printf("Digite o CEP: ");
		scanf("%d", &p[i].cep);
		__fpurge(stdin);
		printf("Digite o dia: ");
		scanf("%d", &p[i].dt_nasc.dia);
		__fpurge(stdin);
		printf("Digite o mes: ");
		scanf("%d", &p[i].dt_nasc.mes);
		__fpurge(stdin);
		printf("Digite o ano: ");
		scanf("%d", &p[i].dt_nasc.ano);
	}
	ordenar(p,n);
	imprimir(p,n);
	free(p);
}
	