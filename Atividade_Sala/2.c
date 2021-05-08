#include <stdio.h>
#include <stdlib.h>

int main(){
	int dia;
	char opcao[1];
	system("clear");	
	do{
			
		printf("Digite o dia da semana: ");
		scanf("%d", &dia);
		switch(dia){
			case 1:
				printf("Domingo\n");
				break;
			case 2:
				printf("Segunda\n");
				break;
			case 3:
				printf("Terça\n");
				break;
			case 4:
				printf("Quarta\n");
				break;
			case 5:
				printf("Quinta\n");
				break;
			case 6:
				printf("Sexta\n");
				break;
			case 7:
				printf("Sábado\n");
				break;
			case 0:
				exit(1);
			default:
				printf("Dia inválido\n");
		}
		printf("De novo? ");
		scanf("[^\n]", opcao);
	}while (strcmp(opcao,"s")==0);
}
