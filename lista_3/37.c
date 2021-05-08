#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct dataNascimento{
	int dia, mes, ano;
};

struct funcionario{
	char nome[35];
	char sexo[2];
	char cargo[30];
	int idade, cpf, codSetor;
	float salario;
	struct dataNascimento dtNasc;
};



int main()
{
	system("clear");
	
	struct funcionario f;

	__fpurge(stdin);
	printf("Digite o nome do funcionario: ");
	scanf("%[^\n]", f.nome);
	__fpurge(stdin);
	printf("Digite a idade do funcionario: ");
	scanf("%d", &f.idade);
	__fpurge(stdin);
	printf("Digite o sexo do funcionario: ");
	scanf("%c", &f.sexo);
	__fpurge(stdin);
	printf("Digite o CPF do funcionario: ");
	scanf("%d", &f.cpf);
	__fpurge(stdin);
	printf("Digite o dia de nascimento do funcionario: ");
	scanf("%d", &f.dtNasc.dia);
	__fpurge(stdin);
	printf("Digite o mes de nascimento do funcionario: ");
	scanf("%d", &f.dtNasc.mes);
	__fpurge(stdin);
	printf("Digite o ano de nascimento do funcionario: ");
	scanf("%d", &f.dtNasc.ano);
	__fpurge(stdin);
	printf("Digite o código do setor onde trabalha o funcionario: ");
	scanf("%d", &f.codSetor);
	__fpurge(stdin);
	printf("Digite o cargo do funcionario: ");
	scanf("%[^\n]", f.cargo);
	__fpurge(stdin);
	printf("Digite o salário do funcionario: ");
	scanf("%f", &f.salario);


	printf("\nNome do funcionário: %s", f.nome);
	printf("\nIdade do funcionário: %d", f.idade);
	printf("\nSexo do funcionário: %s", f.sexo);
	printf("\nCPF do funcionário: %d", f.cpf);
	printf("\nData de nascimento do funcionário: %d/%d/%d", f.dtNasc.dia, f.dtNasc.mes, f.dtNasc.ano);
	printf("\nCódigo do setor do funcionário: %d", f.codSetor);
	printf("\nCargo do funcionário: %s", f.cargo);
	printf("\nSalário do funcionário: %.2f\n", f.salario);


	return 0;
}
