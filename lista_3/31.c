#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>
struct conjunto{
	float n1,n2,n3,soma,prod,med;
};

int main()
{
	struct conjunto c[50];
	int i=0;
	do
	{
		printf("Digite o primeiro valor do %d conjunto: ", i+1);
		scanf("%f'", &c[i].n1);
		printf("Digite o segundo valor do %d conjunto: ", i+1);
		scanf("%f'", &c[i].n2);
		printf("Digite o terceiro valor do %d conjunto: ", i+1);
		scanf("%f", &c[i].n3);

		c[i].soma = c[i].n1 + c[i].n2 + c[i].n3;
		c[i].prod = c[i].n1 * c[i].n2 * c[i].n3;
		c[i].med = c[i].soma/3;


		i++;
	} while ((c[i-1].n1 < c[i-1].n2) && (c[i-1].n2 < c[i-1].n3));

	for (int j = 0; j < i-1; ++j)
	{
		printf("\n\nConjunto %d : %.2f, %.2f, %.2f :", j+1,c[j].n1, c[j].n2, c[j].n3);
		printf("\nSoma: %.2f", c[j].soma);
		printf("\nProduto: %.2f", c[j].prod);
		printf("\nMédia: %.2f\n", c[j].med);

	}

	return 0;
}
