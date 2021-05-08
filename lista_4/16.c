#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int * solicitarPrimeiros(){
	int *p = malloc(10*sizeof(int));
	for (int i = 0; i < 10; ++i)
	{
		printf("Digite o %d número: ", i+1);
		scanf("%d", &p[i]);
	}
	return p;
}

void solicitarOutros(int *p){
	int num;
	char resp[10];
	int total = 10;
	do
	{
		__fpurge(stdin);
		printf("Deseja inserir mais elementos? ");
		scanf("%[^\n]", resp);
		if (strcmp(resp,"sim")==0)
		{
			printf("Deseja inserir mais quantos? ");
			scanf("%d", &num);		
			p = realloc(p,(total+num)*sizeof(int));
			for (int i = total; i < total+num; ++i)
			{
				printf("Digite o %d número: ", i+1);
				scanf("%d", &p[i]);
			}
			total+=num;
		}
	} while (strcmp(resp,"sim")==0);
	for (int i = 0; i < total; ++i)
	{
		printf("%d %o %x\n", p[i], p[i], p[i]);
	}
	printf("\n");
}


int main(){
	system("clear");
	int *p;
	p = solicitarPrimeiros();
	solicitarOutros(p);
}
