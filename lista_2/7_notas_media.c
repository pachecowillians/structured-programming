#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	float n1,n2,n3,media=0;
	char opcao[1];
	printf("Digite a nota 1: ");
	scanf("%f", &n1);
	printf("Digite a nota 2: ");
	scanf("%f", &n2);
	printf("Digite a nota 3: ");
	scanf("%f", &n3);

	printf("\nMenu de médias: \n");
	printf("a) aritimética \n");
	printf("b) ponderada  \n");
	printf("c) harmônica \n\n");
	do
	{
		printf("Digite a letra correspondente:  ");
		scanf("%s", opcao);
	} while ((strcmp("a",opcao)!=0) && (strcmp("b",opcao)!=0) && (strcmp("c",opcao)!=0));
	
	switch(opcao[0]){
		case 'a':
		media = (n1+n2+n3)/3;
		break;
		case 'b':
		media = (n1*3 + n2*3 + n3*4)/10;
		break;
		case 'c':
		media = (3/(1/n1 + 1/n2 + 1/n3));
		break;
	}
	printf("A média é: %.2f\n", media);
}