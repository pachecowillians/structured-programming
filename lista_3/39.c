#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct Endereco
{
	char rua[70];
	int numero;
	char complemento[100];
	char bairro[50];
	int cep;
	char cidade[50];
	char estado[50];
	char pais[50];
};

struct Telefone
{
	int ddd;
	int numero;
};

struct DataAniversario
{
	int dia;
	int mes;
	int ano;
};

struct Pessoa
{
	int nome;
	char email[90];
	struct Endereco end;
	struct Telefone tel;
	struct DataAniversario dtAniversario;
	char observacoes[150];
};


void inserePessoa(struct Pessoa a[], int i, char agenda[][50]){

	__fpurge(stdin);
	a[i].nome=i;
	printf("Digite o nome da %d pessoa: ", i+1);
	scanf("%[^\n]", agenda[a[i].nome]);

	__fpurge(stdin);
	printf("Digite o email da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].email);
	
	__fpurge(stdin);
	printf("Digite o nome da rua da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.rua);
	__fpurge(stdin);
	printf("Digite o número da casa da %d pessoa: ", i+1);
	scanf("%d", &a[i].end.numero);
	__fpurge(stdin);
	printf("Digite o complemento do endereço da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.complemento);
	__fpurge(stdin);
	printf("Digite o bairro da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.bairro);
	__fpurge(stdin);
	printf("Digite o CEP da %d pessoa: ", i+1);
	scanf("%d", &a[i].end.cep);
	__fpurge(stdin);
	printf("Digite a cidade da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.cidade);
	__fpurge(stdin);
	printf("Digite o estado da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.estado);
	__fpurge(stdin);
	printf("Digite o país da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].end.pais);

	__fpurge(stdin);
	printf("Digite o DDD da %d pessoa: ", i+1);
	scanf("%d", &a[i].tel.ddd);
	__fpurge(stdin);
	printf("Digite o número de telefone da %d pessoa: ", i+1);
	scanf("%d", &a[i].tel.numero);

	__fpurge(stdin);
	printf("Digite o dia do aniversário da %d pessoa: ", i+1);
	scanf("%d", &a[i].dtAniversario.dia);
	__fpurge(stdin);
	printf("Digite o mes do aniversário da %d pessoa: ", i+1);
	scanf("%d", &a[i].dtAniversario.mes);
	__fpurge(stdin);
	printf("Digite o ano do aniversário da %d pessoa: ", i+1);
	scanf("%d", &a[i].dtAniversario.ano);

	__fpurge(stdin);
	printf("Digite as observações da %d pessoa: ", i+1);
	scanf("%[^\n]", a[i].observacoes);

}


void exibirPessoa(struct Pessoa p[], int i, int individual, char agenda[][50]){
	if (individual==-1)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("\nNome da %d pessoa: %s",j+1, agenda[p[j].nome]);
			printf("\nEmail da %d pessoa: %s",j+1, p[j].email);
			printf("\nEndereço da %d pessoa: \nRua: %s, \nNúmero: %d, \nComplemento: %s, \nBairro: %s, \nCEP: %d, \nCidade: %s, \nEstado: %s, \nPaís: %s",j+1, p[j].end.rua, p[j].end.numero, p[j].end.complemento, p[j].end.bairro, p[j].end.cep, p[j].end.cidade, p[j].end.estado, p[j].end.pais);
			printf("\nTelefone da %d pessoa: (%d) %d",j+1, p[j].tel.ddd, p[j].tel.numero);
			printf("\nAniversário da %d pessoa: %d/%d/%d",j+1, p[j].dtAniversario.dia, p[j].dtAniversario.mes, p[j].dtAniversario.ano);
			printf("\nObservações sobre a %d pessoa: %s\n",j+1, p[j].observacoes);
		}
	}else if (individual==-2)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("\nNome da %d pessoa: %s",j+1, agenda[p[j].nome]);
			printf("\nTelefone da %d pessoa: (%d) %d",j+1, p[j].tel.ddd, p[j].tel.numero);
			printf("\nEmail da %d pessoa: %s\n",j+1, p[j].email);
		}
	}
	else{
		printf("\nNome da %d pessoa: %s",individual+1, agenda[p[individual].nome]);
		printf("\nEmail da %d pessoa: %s",individual+1, p[individual].email);
		printf("\nEndereço da %d pessoa: \nrua: %s, \nnúmero: %d, \ncomplemento: %s, \nbairro: %s, \nCEP: %d, \ncidade: %s, \nestado: %s, \npaís: %s,",individual+1, p[individual].end.rua, p[individual].end.numero, p[individual].end.complemento, p[individual].end.bairro, p[individual].end.cep, p[individual].end.cidade, p[individual].end.estado, p[individual].end.pais);
		printf("\nTelefone da %d pessoa: (%d) %d",individual+1, p[individual].tel.ddd, p[individual].tel.numero);
		printf("\nAniversário da %d pessoa: %d/%d/%d",individual+1, p[individual].dtAniversario.dia, p[individual].dtAniversario.mes, p[individual].dtAniversario.ano);
		printf("\nObservações sobre a %d pessoa: %s\n",individual+1, p[individual].observacoes);
	}
	
}

void buscarPessoa(struct Pessoa p[], int i, int op, char agenda[][50]){

	if (op==1)
	{
		char nome[50];
		int achou=0;
		__fpurge(stdin);
		printf("Digite o nome da pessoa: ");
		scanf("%[^\n]", nome);

		for (int j = 0; j < i; ++j)
		{
			if (comparaPrimeiroNome(agenda[p[j].nome],nome)==1)
			{
				exibirPessoa(p,i,j, agenda);
				achou=1;
			}
		}
		if (achou==0)
		{
			printf("\nPessoa não encontrada\n");
		}
	}
	else if (op==2)
	{
		int mes;
		int achou=0;
		__fpurge(stdin);
		printf("Digite o mês de aniversário da pessoa: ");
		scanf("%d", &mes);

		for (int j = 0; j < i; ++j)
		{
			if (p[j].dtAniversario.mes==mes)
			{
				exibirPessoa(p,i,j, agenda);
				achou=1;
			}
		}
		if (achou==0)
		{
			printf("\nPessoa não encontrada\n");
		}
	}
	else if (op==3)
	{
		int dia, mes;
		int achou=0;
		__fpurge(stdin);
		printf("Digite o dia do aniversário da pessoa: ");
		scanf("%d", &dia);
		__fpurge(stdin);
		printf("Digite o mês de aniversário da pessoa: ");
		scanf("%d", &mes);

		for (int j = 0; j < i; ++j)
		{
			if (p[j].dtAniversario.mes==mes && p[j].dtAniversario.dia==dia)
			{
				exibirPessoa(p,i,j, agenda);
				achou=1;
			}
		}
		if (achou==0)
		{
			printf("\nPessoa não encontrada\n");
		}
	}
	
}

int comparaPrimeiroNome(char nomeTodo[], char nomeComparar[]){

	int espaco = 0, pos=0, igual=1;
	for (int i = 0; i < strlen(nomeTodo); ++i)
	{
		if (nomeTodo[i]==' ' && espaco!=1){
			espaco=1;
			pos=i;

		}
	}
	if (espaco==1)
	{
		if (pos==strlen(nomeComparar))
		{
			for (int i = 0; i < pos; ++i)
			{
				if (nomeTodo[i]!=nomeComparar[i])
				{
					igual=0;
				}
			}
		}
		else{
			igual=0;
		}
	}
	else{
		if (strlen(nomeTodo)==strlen(nomeComparar))
		{
			for (int i = 0; i < pos; ++i)
			{
				if (nomeTodo[i]!=nomeComparar[i])
				{
					igual=0;
				}
			}
		}
		else{
			igual=0;
		}
	}
	return igual;
}

void ordenaVetorChar(struct Pessoa p[], int i, char agenda[][50]){
	struct Pessoa aux;
	for (int j = 0; j < i; ++j)
	{
		for (int k = 0; k < i; ++k)
		{
			if (strcmp(agenda[p[j].nome], agenda[p[k].nome])<=0)
			{
				aux = p[j];
				p[j]= p[k];
				p[k] = aux;
			}
		}
	}
}

int main()
{
	int quantidade = 100;
	struct Pessoa p[100]; //como cada pessoa tem um nome, entendi que era para criar essa variável no item B.
	int i=0, op, op2;
	char continuar[2];
	char agenda[100][50];
	system("clear");
	do
	{
		system("clear");
		printf("\n1 - Adicionar pessoa");
		printf("\n2 - Buscar pessoa");
		printf("\n3 - Mostrar agenda");
		printf("\n4 - Sair");
		printf("\nEscolha a opção: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			if (i>=quantidade)
				printf("\nTamanho do vetor atingido\n");
			else{	
				inserePessoa(p, i, agenda);
				i++;
				ordenaVetorChar(p, i, agenda);
			}
			break;
			case 2:
			printf("\n1 - Buscar por primeiro nome");
			printf("\n2 - Buscar por mês de aniversário");
			printf("\n3 - Buscar por dia e mês de aniversário");
			printf("\nEscolha a opção: ");
			scanf("%d", &op2);
			if (op2==1)
				buscarPessoa(p, i, 1, agenda);
			else if(op2==2)
				buscarPessoa(p, i, 2, agenda);
			else if(op2==3)
				buscarPessoa(p, i, 3, agenda);
			break;
			case 3:
			printf("\n1 - Imprime nome, telefone e e-mail");
			printf("\n2 - Imprime todos os dados");
			printf("\nEscolha a opção: ");
			scanf("%d", &op2);
			if (op2==1)
				exibirPessoa(p, i, -2, agenda);
			else if(op2==2)
				exibirPessoa(p, i, -1, agenda);
			break;
			case 4:
			exit(1);
			break;

		}
		do
		{
			printf("\nDeseja voltar ao menu? (s/n): ");
			scanf("%s", continuar);
		} while (strcmp(continuar,"s")!=0 && strcmp(continuar,"n")!=0);
		
		
	} while (strcmp(continuar,"s")==0);

	return 0;
}


