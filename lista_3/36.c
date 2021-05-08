#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct produto{
	int codigo;
	char nome[35];
	float preco;
};

void ler(struct produto p[], int i){

	__fpurge(stdin);
	printf("Digite o código do %d produto: ", i+1);
	scanf("%d", &p[i].codigo);
	__fpurge(stdin);
	printf("Digite o nome do %d produto: ", i+1);
	scanf("%[^\n]", p[i].nome);
	__fpurge(stdin);
	printf("Digite o preço do %d produto: ", i+1);
	scanf("%f", &p[i].preco);

}

void buscar(struct produto p[], int i){

	int pos = 0, achou=0, cod=0;
	__fpurge(stdin);
	printf("Digite o código do produto: ");
	scanf("%d", &cod);

	for (int j = 0; j < i; ++j)
	{
		if (cod == p[j].codigo)
		{
			pos = j;
			achou=1;
		}
	}

	if (achou==1){
		printf("\nO produto está na %d posição\n", pos+1);
		mostrar(p,i,pos);
	}
	else{
		printf("\nO produto não se encontra no vetor\n");
	}
}

void mostrar(struct produto p[], int i, int individual){
	if (individual==-1)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("\nCódigo do %d produto: %d",j+1, p[j].codigo);
			printf("\nNome do %d produto: %s",j+1, p[j].nome);
			printf("\nPreço do %d produto: %.2f\n",j+1, p[j].preco);
		}
	}
	else{
		printf("\nCódigo do %d produto: %d",individual+1, p[individual].codigo);
		printf("\nNome do %d produto: %s",individual+1, p[individual].nome);
		printf("\nPreço do %d produto: %.2f\n",individual+1, p[individual].preco);
	}
	
}

int main()
{
	system("clear");
	int quantidade = 10;
	struct produto p[10];
	int op, i=0;
	char continuar[1];
	do
	{
		system("clear");
		printf("\n1 - Adicionar produto");
		printf("\n2 - Buscar produto");
		printf("\n3 - Mostrar produtos");
		printf("\n4 - Sair");
		printf("\nEscolha a opção: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			if (i>=quantidade)
				printf("\nTamanho do vetor atingido\n");
			else{	
				ler(p, i);
				i++;
			}
			break;
			case 2:
			buscar(p, i);
			break;
			case 3:
			mostrar(p, i, -1);
			break;
			case 4:
			exit(1);
			break;
		}

		printf("\nDeseja voltar ao menu? (s/n): ");
		scanf("%s", continuar);
		
	} while (strcmp(continuar,"s")==0);

	
	

	return 0;
}
