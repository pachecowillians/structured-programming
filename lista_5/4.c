#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cod, tempoServico;
	char profissao[30];
}Funcionario;

void GravarArq(Funcionario *f, int tam){
	FILE *arq = fopen("emp.txt", "a+");
	for (int i = 0; i < tam; ++i)
	{
		fprintf(arq, "%d %d %s\n", f[i].cod, f[i].tempoServico, f[i].profissao);
	}
}

void LerFunc(Funcionario *f, int n){
	char op;
	for (int i = 0; i < n; ++i)
	{
		__fpurge(stdin);
		printf("Digite o código do Funcionário: ");
		scanf("%d", &f[i].cod);
		__fpurge(stdin);
		printf("Digite o tempo de serviço do Funcionário: ");
		scanf("%d", &f[i].tempoServico);
		__fpurge(stdin);
		printf("Digite a profissão do Funcionário: ");
		scanf("%[^\n]", f[i].profissao);
	}
	
}

int main(){
	system("clear");
	int n;

	__fpurge(stdin);
	printf("Deseja cadastrar quantos funcionários?");
	scanf("%d", &n);
	
	Funcionario *f = malloc(n*sizeof(Funcionario));
	
	LerFunc(f, n);
	GravarArq(f, n);

	free(f);

}
