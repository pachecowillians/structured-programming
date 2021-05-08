#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct livro{
	char titulo[35], autor[20];
	int ano;
};

void ler(struct livro l[], int i){

	__fpurge(stdin);
	printf("Digite o título do %d livro: ", i+1);
	scanf("%[^\n]", l[i].titulo);
	__fpurge(stdin);
	printf("Digite o autor do %d livro: ", i+1);
	scanf("%[^\n]", l[i].autor);
	__fpurge(stdin);
	printf("Digite o ano do %d livro: ", i+1);
	scanf("%d", &l[i].ano);

}

void buscar(struct livro l[], int i){

	char t[35];
	int pos = 0, achou=0;
	__fpurge(stdin);
	printf("Digite o título do livro: ");
	scanf("%[^\n]", t);

	for (int j = 0; j < i; ++j)
	{
		if (strcmp(t,l[j].titulo)==0)
		{
			pos = j;
			achou=1;
		}
	}

	if (achou==1)
		printf("\nO livro está na %d posição\n", pos+1);
	else
		printf("\nO livro não se encontra no vetor\n");
}

void mostrar(struct livro l[], int i){
	for (int j = 0; j < i; ++j)
	{
		printf("\nTítulo do %d livro: %s",i+1, l[j].titulo);
		printf("\nAutor do %d livro: %s",i+1, l[j].autor);
		printf("\nAno do %d livro: %d\n",i+1, l[j].ano);

	}
}

int main()
{
	struct livro l[25];
	int op, i=0;
	char continuar[1];
	do
	{
		printf("\n1 - Adicionar livro");
		printf("\n2 - Buscar livro");
		printf("\n3 - Mostrar livros");
		printf("\n4 - Sair");
		printf("\nEscolha a opção: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			if (i>=25)
				printf("\nTamanho do vetor atingido\n");
			else{	
				ler(l, i);
				i++;
			}
				break;
			case 2:
				buscar(l, i);
				break;
			case 3:
				mostrar(l, i);
				break;
			case 4:
				exit(1);
				break;
		}

		printf("\nDeseja continuar? (s/n): ");
		scanf("%s", continuar);
		printf("%s\n", continuar);
		
	} while (strcmp(continuar,"s")==0);

	
	

	return 0;
}
