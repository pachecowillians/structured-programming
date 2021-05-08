#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int negativos(float *vet, int N){
	int cont=0;
	for (int i = 0; i < N; ++i)
	{
		if (vet[i]<0)
		{
			cont++;
		}
	}
	return cont;
}

void main(void) {
	int n, neg=0;
	float *vet;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	vet = malloc(n*sizeof(float));
	printf("Digite o vetor: \n");

	for (int i = 0; i < n; ++i)
	{
		scanf("%f", &vet[i]);
	}
	neg = negativos(vet,n);

	printf("negativos: %d\n", neg);
	free(vet);
}