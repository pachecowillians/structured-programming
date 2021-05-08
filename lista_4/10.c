#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

struct Ponto{
	float x, y;
};

int main(){
	system("clear");
	#define QUANTIDADE_DE_PONTOS 5 //constante
	struct Ponto pontos[QUANTIDADE_DE_PONTOS-1];
	//dados de Registro Ponto, com tamanho QUANTIDADE_DE_PONTOS
	int menor_distancia_ao_quadrado, ponto_mais_proximo;
	for (int i = 0; i < (QUANTIDADE_DE_PONTOS-1); ++i)
	{
		scanf("%f", &pontos[i].x);
		scanf("%f", &pontos[i].y);
	}

	menor_distancia_ao_quadrado = INT_MAX;
	ponto_mais_proximo = 1;

	for (int i = 1; i < (QUANTIDADE_DE_PONTOS-1); ++i)
	{
		float distancia_ao_quadrado = (pontos[i].x-pontos[0].x)*(pontos[i].x-pontos[0].x)+(pontos[i].y-pontos[0].y)* (pontos[i].y-pontos[0].y);
		if (distancia_ao_quadrado < menor_distancia_ao_quadrado)
		{
			ponto_mais_proximo = i;
			menor_distancia_ao_quadrado = distancia_ao_quadrado;
		}
	}
	printf("x:%f y:%f\n", pontos[ponto_mais_proximo].x,pontos[ponto_mais_proximo].y);
}
