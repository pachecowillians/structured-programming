#include <stdio.h>
#include <stdlib.h>

int CalculaAij(int **A, int **B, int i, int j, int n){
	int soma = 0;
	for (int k = 0; k < n; ++k)
	{
		soma += A[i][k] *B[k][j];
	}
	return soma;
}

void PrintaMatrizC(int **C, int it, int jt){
	printf("\nMatriz Resultante: \n");
	for (int i = 0; i < it; ++i)
	{
		for (int j = 0; j < jt; ++j)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}

void LerMatriz(int **M, int it, int jt){
	for (int i = 0; i < it; ++i)
	{
		for (int j = 0; j < jt; ++j)
		{
			printf("Digite a matriz na posição [%d][%d]: ",i,j);
			scanf("%d", &M[i][j]);
		}
	}
}

void GerarMatResultante(int **A,int **B,int **C, int it, int jt, int ca){
	for (int i = 0; i < it; ++i)
		{
			for (int j = 0; j < jt; ++j)
			{
				C[i][j] = CalculaAij(A,B,i,j,ca);
			}
		}
}

int main(){
	system("clear");
	int la, lb, ca, cb, **A, **B, **C;

	__fpurge(stdin);
	printf("Digite o numero de linhas da matriz A: ");
	scanf("%d", &la);
	__fpurge(stdin);
	printf("Digite o numero de colunas da matriz A: ");
	scanf("%d", &ca);

	A = (int **)malloc(la*sizeof(int));
	for (int i = 0; i < la; ++i)
		A[i] = malloc(ca*sizeof(int *));

	__fpurge(stdin);
	printf("Digite o numero de linhas da matriz B: ");
	scanf("%d", &lb);
	__fpurge(stdin);
	printf("Digite o numero de colunas da matriz B: ");
	scanf("%d", &cb);

	B = malloc(lb*sizeof(int));
	for (int i = 0; i < lb; ++i)
		B[i] = malloc(cb*sizeof(int));

	if(ca!=lb){
		printf("Não podemos multiplicar as matrizes!\n");
	}else{
		printf("Matriz A: \n");
		LerMatriz(A, la, ca);

		printf("Matriz B: \n");
		LerMatriz(B, lb, cb);

		C = malloc(la*sizeof(int));
		for (int i = 0; i < la; ++i)
			C[i] = malloc(cb*sizeof(int));

		GerarMatResultante(A,B,C,la,cb,ca);
		PrintaMatrizC(C,la,cb);
	}
	free(A);
	free(B);
	free(C);

}