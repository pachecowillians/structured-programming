#include <stdlib.h>
#include <stdio.h>

int main(){
	float n1,n2,n3,n4;
	char nome[10], opcao[1];
	do
	{
		system("clear");
		__fpurge(stdin);
		printf("Digite o nome:");
		scanf("%[^\n]",nome);
		do
		{
			printf("Digite a nota 1 de %s: ",nome);
			scanf("%f", &n1);
		} while (n1<0 || n1>10);
		
		do
		{
			printf("Digite a nota 2 de %s: ",nome);
			scanf("%f", &n2);
		} while (n2<0 || n2>10);
		
		do
		{
			printf("Digite a nota 3 de %s: ",nome);
			scanf("%f", &n3);
		} while (n3<0 || n3>10);
		
		do
		{
			printf("Digite a nota 4 de %s: ",nome);
			scanf("%f", &n4);
		} while (n4<0 || n4>10);
		
		
		printf("Média: %.2f\n",((n1+n2+n3+n4)/4));
		printf("Deseja calcular a média novamente? (S/N)");
		scanf("%s",&opcao);
	} while (strcmp(opcao,"s")==0 || strcmp(opcao,"S")==0);
	
	

}
