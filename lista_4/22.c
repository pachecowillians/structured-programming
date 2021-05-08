#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void valores(int *min, int *max, float *med, int vetor[], int tam){
	*min = INT_MAX;
	*max = INT_MIN;
	float soma=0;
	for (int i = 0; i < tam; ++i)
	{
		soma += vetor[i];
		if (vetor[i] < *min)
			*min = vetor[i];
		if (vetor[i] > *max)
			*max = vetor[i];
	}
	*med = soma/10;

}

void main(void) {
	int min, max, vetor[10], tam=10;
	float med;

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &vetor[i]);
	}
	valores(&min, &max, &med, vetor, tam);

	printf("Min: %d\n", min);
	printf("Max: %d\n", max);
	printf("Med: %.2f\n", med);


	
}