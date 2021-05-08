#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct {
char nome[80];
float preco;
} PROD;

void imprimir(PROD *p){
	printf("\n");
	for (int i = 0; i < 20; ++i)
	{
		printf("Produto: %s\n", p[i].nome);
		printf("Preco: %.2f\n\n", p[i].preco);
	}
}

void ordenar(PROD *p){
	PROD aux;
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
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

void inflacionar(PROD *p){
	printf("\n");
	for (int i = 0; i < 20; ++i)
	{
		if (p[i].preco<100)
		{
			p[i].preco*=1.05;
		}
	}
}

int main(){
	system("clear");
	PROD p[20], *pont;
	pont = p;
	for (int i = 0; i < 20; ++i)
	{
		__fpurge(stdin);
		scanf("%[^\n]", p[i].nome);
		__fpurge(stdin);
		scanf("%f", &p[i].preco);
	}
	ordenar(pont);
	inflacionar(pont);
	imprimir(pont);
}
	