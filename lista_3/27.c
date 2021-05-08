#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
	int a[10], v, tamanho =10, achou=0;
	char op[1];
	for (int i = 0; i < tamanho; i++)
	{
		printf("Digite o %d elemento: ", i+1);
		scanf("%d", &a[i]);
	}

	do
	{
		achou = 0;
		printf("Digite o valor a ser removido:");
		scanf("%d", &v);

		for (int i = 0; i < tamanho; ++i)
		{
			if (a[i]==v)
			{
				for (int j = i; j < tamanho-1; ++j)
				{
					a[j] = a[j+1];
				}

				tamanho--;
				achou=1;
			}
		}
		if (achou==0)
		{
			printf("O valor não foi encontrado no vetor. Nada a ser feito. \n");
		}
		printf("\n");
		for (int i = 0; i < tamanho; ++i)
		{
			printf("%d ", a[i]);
		}

		printf("\nDeseja remover outro? (s/n)");
		scanf("%s", op);

	} while (strcmp(op,"s")==0);

	return 0;
}
