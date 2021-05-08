#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
	int a[100], i=0,j,k, num, quantidade; 
	float fat;
 
 
	printf("Digite a quantidade de números: ");
	scanf("%d", &quantidade);
	do
	{
		printf("\nDigite o número: ");
		scanf("%d", &a[i]);
		
		for (int j = 0; j < i+1; ++j)
		{
			fat = 1;
			for (int k = 1; k <= a[j]; ++k)
			{
				fat *= k;
			}
			printf("\nValor lido: %d", a[j]);
			printf("\nFatorial do valor lido: %.0f\n", fat);
		}
		i++;
	} while (i<quantidade);

 return 0;
}
