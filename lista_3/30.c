#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>
int main()
{
	long int num, produto=1;
	do
	{
		printf("Digite o número: ");
		scanf("%ld", &num);
		if (num!=0)
			produto*= num;
		
	} while (num!=0);
	printf("\nProduto: %ld\n", produto);

	return 0;
}
