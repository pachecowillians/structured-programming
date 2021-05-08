#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void RetornaValores(int vet[], int n, int *men, int *num){
	*men = INT_MAX;
	*num = 0;
	for (int i = 0; i < n; ++i)
	{
		if(vet[i]<*men)
			*men = vet[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (vet[i] == *men)
		{
			*num = *num + 1;
		}
	}
}

void main(void) {
	int n, min, num;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int vet[n];
	printf("Digite o vetor: \n");

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &vet[i]);
	}

	RetornaValores(vet, n, &min, &num);

	printf("Menor valor: %d\n", min);
	printf("Numero de vezes: %d\n", num);

}