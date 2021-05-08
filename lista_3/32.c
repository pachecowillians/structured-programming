#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct aluno{
	char nome[20];
	int matricula;
	char curso[70];
};
	
int main()
{
	struct aluno a[5];
	for (int i = 0; i < 5; ++i)
	{
		__fpurge(stdin);
		printf("Nome do %d aluno: ", i+1);
		scanf("%[^\n]", a[i].nome);

		__fpurge(stdin);
		printf("Matrícula do %d aluno: ", i+1);
		scanf("%d", &a[i].matricula);

		__fpurge(stdin);
		printf("Curso do %d aluno: ", i+1);
		scanf("%[^\n]", a[i].curso);
	}
	
	for (int i = 0; i < 5; ++i)
	{
		printf("\nNome do %d aluno: %s", i+1, a[i].nome);
		printf("\nMatrícula do %d aluno: %d", i+1, a[i].matricula);
		printf("\nCurso do %d aluno: %s\n", i+1, a[i].curso);
	}

	return 0;
}
