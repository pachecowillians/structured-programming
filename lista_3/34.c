#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct dataNascimento{
	int dia, mes, ano;
};

struct pessoa{
	char nome[20];
	float altura;
	struct dataNascimento dtNasc;
};

int main()
{
	struct pessoa p[10];

	for (int i = 0; i < 10; ++i)
	{
		__fpurge(stdin);
		printf("Digite o nome da %d pessoa: ", i+1);
		scanf("%[^\n]", p[i].nome);
		__fpurge(stdin);
		printf("Digite a altura da %d pessoa: ", i+1);
		scanf("%f", &p[i].altura);
		__fpurge(stdin);
		printf("Digite o dia de nascimento da %d pessoa: ", i+1);
		scanf("%d", &p[i].dtNasc.dia);
		__fpurge(stdin);
		printf("Digite o mês de nascimento da %d pessoa: ", i+1);
		scanf("%d", &p[i].dtNasc.mes);
		__fpurge(stdin);
		printf("Digite o ano de nascimento da %d pessoa: ", i+1);
		scanf("%d", &p[i].dtNasc.ano);
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("\nNome da %d pessoa: %s",i+1, p[i].nome);
		printf("\nAltura da %d pessoa: %.2f",i+1, p[i].altura);
		printf("\nData nascimento da %d pessoa: %d/%d/%d\n",i+1, p[i].dtNasc.dia, p[i].dtNasc.mes, p[i].dtNasc.ano);
	}

	return 0;
}
