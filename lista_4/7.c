#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
	system("clear");
	float mat[5][12]; //meses são as colunas e as vendas são as linhas
	int i,j;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 12; ++j)
		{
			printf("Digite o %dx%d elemento: ", i,j);
			scanf("%f", &mat[i][j]);
		}
	}
	printf("\n");
	printf("Digite o numero da linha que representa o produto: \n");
	__fpurge(stdin);
	scanf("%d", &i);
	printf("Digite o número do mês: \n");
	__fpurge(stdin);
	scanf("%d", &j);

	printf("%.2f\n", mat[i-1][j-1]); //como a contagem geralmente começa em 1, e o vetor começa em zero, consertei essa diferença
}
