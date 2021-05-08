#include <stdlib.h>
#include <stdio.h>

float nota1, nota2, nota3, media;
char opcao[1], nome[30];

int main(){
	do{
		//fflush(stdin);windows
		__fpurge(stdin);
		printf("Digite o nome do aluno: \n");
		scanf("%[^\n]",nome);
		do{
			printf("Digite a primeira nota do %s: \n",nome);
			scanf("%f", &nota1);
		}while(nota1<0 || nota1>10);
		
		do{
			printf("Digite a segunda nota do %s: \n",nome);
			scanf("%f", &nota2);
		}while(nota2<0 || nota2>10);
		
		do{
			printf("Digite a segunda nota do %s: \n",nome);
			scanf("%f", &nota3);
		}while(nota3<0 || nota3>10);
		
		media = (nota1+nota2+nota3)/3;
		
		printf("O aluno %s obteve média %.2f \n", nome, media);
		
		printf("Digite S para sair e C para continuar: \n");
		scanf("%s", &opcao);
	}while(strcmp(opcao,"S")!=0 && strcmp(opcao,"s")!=0);
	return 0;
}
