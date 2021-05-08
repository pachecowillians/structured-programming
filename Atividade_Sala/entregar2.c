#include <stdio.h>
#include <stdlib.h>

int main(){
	__fpurge(stdin);
	int opcao,cont=0;
	char nome[20];
	float soma=0,nota=0;
	char voltar[1];
	printf("Digite o nome do aluno: ");
	scanf("%[^\n]",nome);
	system("clear");
	do
	{
		printf("Aluno: %s\n",nome);
		printf("\nMenu:\n");
		printf("1 - Informar nova nota\n");
		printf("2 - Calcular média\n");
		printf("3 - Sair\n");
		printf("\nDigite o comando: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				do
				{	
					system("clear");
					printf("Digite a nota: ");
					scanf("%f", &nota);
				} while (nota<0 || nota>10);
				soma += nota;
				cont+=1;
				system("clear");
				break;
			case 2:
				printf("\nMédia: %.2f \n", (soma/cont));
				printf("\nDigite qualquer valor para voltar ao menu: ");
				scanf("%s",voltar);
				system("clear");
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("Valor inválido\n");
				system("clear");
				break;
		}
	} while (opcao!=3);


}