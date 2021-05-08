#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
	float n1[50], n2[50], media[50];
	int i=0;
	do
	{
		printf("Digite a primeira nota do %d aluno: ", i+1);
		scanf("%f", &n1[i]);
		printf("Digite a segunda nota do %d aluno: ", i+1);
		scanf("%f", &n2[i]);
		media[i] = (n1[i] + n2[i])/2;
		i++;
	} while (n1[i-1]!=-1);

	for (int j = 0; j < i-1; ++j)
	{
		
		if (media[j] >= 7)
			printf("\nAluno %d aprovado!\n", j+1);
		else
			printf("\nAluno %d reprovado!\n", j+1);
	}

	return 0;
}
