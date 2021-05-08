#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(){
	char nome[10];
	do
	{
		do
		{
			printf("Digite: ");
			scanf("%s", nome);
		} while (strcmp(nome,"SIM")!=0 && strcmp(nome,"NAO")!=0 && strcmp(nome,"SAIR")!=0);
		if (strcmp(nome,"SIM")==0)
			printf("1\n");
		else if (strcmp(nome,"NAO")==0)
			printf("0\n");
	} while (strcmp(nome,"SAIR")!=0);
	return 0;
}