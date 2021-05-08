#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int numero, capacidade, alunos;	

	printf("Digite o número da sala: ");
	scanf("%d", &numero);	
	printf("Digite a capacidade da sala: ");	
	scanf("%d", &capacidade);
	printf("Digite o número de alunos matriculados na sala: ");
	scanf("%d", &alunos);	

	if (capacidade>alunos)
		printf("A sala %d está ocupada com %d alunos e pode comportar %d alunos.\n", numero, alunos, capacidade );
	else if (capacidade==alunos)
		printf("A sala %d está lotada de %d alunos e pode comportar %d alunos.\n", numero, alunos, capacidade );
	else if (capacidade<alunos)
		printf("A sala %d está superlotada com %d alunos e pode comportar %d alunos.\n", numero, alunos, capacidade );
	
	return 0;
}