#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main(){
	system("clear");
	float m, n, **p;
	float mediaCPar=0, mediaLImpar=0;
	int contapar=0, contaimpar=0;
	printf("Digite o número de linhas: ");
	scanf("%f", &m);
	printf("Digite o número de colunas: ");
	scanf("%f", &n);

	p = malloc(m*sizeof(float));
	for (int i = 0; i < m; ++i)
		p[i] = malloc(n*sizeof(float));


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			//printf("Digite o valor da posição %dx%d:", i,j);
			scanf("%f", &p[i][j]);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((j+1)%2==0) //considerei que a contagem começava no 1 e não no zero
			{
				mediaCPar+=p[i][j];
				contapar++;
			}
			if ((i+1)%2!=0) //considerei que a contagem começava no 1 e não no zero
			{
				mediaLImpar+=p[i][j];
				contaimpar++;
			}
		}
	}

	mediaCPar/=contapar;
	mediaLImpar/=contaimpar;

	printf("Media Colunas Pares: %.2f\n", mediaCPar);
	printf("Media Linhas Ímpares: %.2f\n", mediaLImpar);

}
	