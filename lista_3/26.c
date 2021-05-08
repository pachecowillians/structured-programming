#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int a[10], erro=0, j=0, v=0;
    do
	{
		
		do
		{
			erro=0;
			printf("Digite o %d valor: ", j+1);
			scanf("%d", &v);
			for (int i = 0; i < j; i++)
			{
				if (a[i]==v){
					erro = 1;
					printf("Valor inválido! Os números não podem repetir. ");
				}
			}	
		} while (erro!=0);
		a[j] = v;
		j++;
		
	} while (j<10);
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	
    return 0;
}
