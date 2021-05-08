#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void LerVetor(int *p){
	for (int i = 0; i < 10; ++i)
	{
		printf("Digite o %d elemento: ", i);
		scanf("%d", &p[i]);
	}
}

void ImprimirVetor(int v[10]){
	for (int i = 0; i < 10; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

void ImprimirVetorPares(int v[10]){
	for (int i = 0; i < 10; ++i)
		if(v[i]%2==0)
			printf("%d ", v[i]);
	printf("\n");
}

void ImprimirVetorImpares(int v[10]){
	for (int i = 0; i < 10; ++i)
		if(v[i]%2!=0)
			printf("%d ", v[i]);
	printf("\n");
}

void contParesPosImpar(int v[10]){
	int j=0	;
	for (int i = 0; i < 10; ++i)
		if(v[i]%2==0 && i%2!=0)
			j++;
	printf("Quantidade: %d\n", j);
}

void contImparPosPar(int v[10]){
	int j=0;
	for (int i = 0; i < 10; ++i)
		if(v[i]%2!=0 && i%2==0)
			j++;
	printf("Quantidade: %d\n", j);
}

void ImprimirVetorInverso(int v[10]){
	for (int i = 9; i >= 0; --i)
		printf("%d ", v[i]);
	printf("\n");
}

void menu(int v[10]){
	int op,*p;
	p = v;
	do{
		printf("1 - Ler Vetor de inteiros de 10 posições\n");
		printf("2 - Imprimir Vetor\n");
		printf("3 - Exibir apenas os números pares do vetor\n");
		printf("4 - Exibir apenas os números ímpares do vetor\n");
		printf("5 - Exibir quantos números pares existem em posições ímpares do vetor\n");
		printf("6 - Exibir quantos números ímpares existem em posições pares do vetor\n");
		printf("7 – Imprimir o vetor na ordem inversa\n");
		printf("8 – Sair\n");
		scanf("%d", &op);
		system("clear");
		switch(op){
			case 1:
				LerVetor(p);
				system("clear");
				break;
			case 2:
				ImprimirVetor(v);
				break;
			case 3:
				ImprimirVetorPares(v);
				break;
			case 4:
				ImprimirVetorImpares(v);
				break;
			case 5:
				contParesPosImpar(v);
				break;
			case 6:
				contImparPosPar(v);
				break;
			case 7:
				ImprimirVetorInverso(v);
				break;
			default:
				op=8;
				break;

		}
	}while(op!=8);
}

int main(){
	system("clear");
	int vet[10], *p;
	menu(vet);
}
