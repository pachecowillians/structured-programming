#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define QUANTIDADE_DE_PONTOS 5 //constante

typedef struct{
	float x, y;
}Ponto;

Ponto *lerPontos(int *tot){
	Ponto *p1;
	p1 = malloc((*tot)*sizeof(Ponto));
	for (int i = 0; i < *tot; ++i)
	{
		scanf("%f", &p1[i].x);
		scanf("%f", &p1[i].y);
	}
	*tot = 5;
	return p1;
}

Ponto *relerPontos(Ponto *p1, int *tot){
	int qtd;
	printf("Deseja adicionar mais quantos?");
	scanf("%d", &qtd);
	p1 = realloc(p1, ((*tot)+qtd)*sizeof(Ponto));
	for (int i = *tot; i < (*tot)+qtd; ++i)
	{
		scanf("%f", &p1[i].x);
		scanf("%f", &p1[i].y);
	}
	*tot += qtd;
	return p1;
}
void mostrarPontos(Ponto *p1, int *tot){

	for (int i = 0; i < *tot; ++i)
	{
		printf("%.2f %.2f \n", p1[i].x, p1[i].y);
	}
}

Ponto *alterarPontos(Ponto *p1,int *tot){
	for (int i = 0; i < *tot; ++i)
	{
		scanf("%f", &p1[i].x);
		scanf("%f", &p1[i].y);
	}
	return p1;
}

void CalcularPontoMaisProximo(Ponto *pontos, int *tot){

	int menor_distancia_ao_quadrado, ponto_mais_proximo;
	
	menor_distancia_ao_quadrado = INT_MAX;
	ponto_mais_proximo = 1;

	for (int i = 1; i < ((*tot)-1); ++i)
	{
		float distancia_ao_quadrado = (pontos[i].x-pontos[0].x)*(pontos[i].x-pontos[0].x)+(pontos[i].y-pontos[0].y)* (pontos[i].y-pontos[0].y);
		if (distancia_ao_quadrado < menor_distancia_ao_quadrado)
		{
			ponto_mais_proximo = i;
			menor_distancia_ao_quadrado = distancia_ao_quadrado;
		}
	}
	printf("x:%.2f y:%.2f\n", pontos[ponto_mais_proximo].x,pontos[ponto_mais_proximo].y);
}

void menu(int tamanho;){
	int op=0,totalPontos=0, *totPont;
	Ponto *pontos, *pontosAux;
	totalPontos = QUANTIDADE_DE_PONTOS;
	totPont = &totalPontos;
	pontos = malloc(QUANTIDADE_DE_PONTOS*sizeof(Ponto));

	do
	{
		printf("1 - Ler cinco pontos de coordenadas cartesianas (x,y) \n");
		printf("2 - Adicionar novos pontos cartesianos com a entrada da quantidade adicional de leituras \n");
		printf("3 - Alterar todos os pontos lidos, até o momento, no vetor \n");
		printf("4 - Obter o cálculo do ponto mais próximo do primeiro ponto lido \n");
		printf("5 - Mostrar pontos \n");
		printf("6 - Sair.\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				system("clear");
				pontosAux = lerPontos(totPont);
				system("clear");
				break;
			case 2:
				system("clear");
				pontosAux = relerPontos(pontosAux, totPont);
				system("clear");
				break;
			case 3:
				system("clear");
				pontosAux = alterarPontos(pontosAux, totPont);
				system("clear");
				break;
			case 4:
				system("clear");
				CalcularPontoMaisProximo(pontosAux, totPont);
				break;
			case 5:
				system("clear");
				mostrarPontos(pontosAux, totPont);
				break;
		}
	} while (op!=6);
	free(pontos);	
}



int main(){
	system("clear");
	menu();
}
