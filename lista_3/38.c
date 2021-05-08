#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
	int v;
	system("clear");
	printf("Digite o número: ");
	scanf("%d", &v);

	for (int i = 0; i <= v; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			printf("%d ",i*j );
		}
		printf("\n");
	}

	return 0;
}
