// ---------------------------------------- FUNC. BUSCA -----------------------------------
//Funções de busca/alteração nos arquivos

#ifndef BUSCA_H
#define BUSCA_H

void BuscarInformacoesTrecho(int codTrecho, Data *dtInicio, Data *dtFim, float *milhas){
	int op;

	FILE *arq = AbrirArquivo("Trecho.dat","rb");
	Trecho *t1;
	t1 = malloc(sizeof(Trecho));

	int cont=0;
	Trecho t;
	while(fread(&t, sizeof(t),1, arq)==1){
		t1[cont] = t;
		t1 = realloc(t1,(cont+2)*sizeof(Trecho));
		cont++;
	}

	for(int i=0; i<cont; i++){
		if(t1[i].codTrecho==codTrecho){
			*milhas = t1[i].milhas;
		}
	}
}

int BuscaVetorCidades(int *vetCidades, int tam, int val){
	int resp=0;
	for (int i = 0; i < tam; ++i)
	{
		if(vetCidades[i] == val)
			resp =1;
	}
	return resp;
}

void PesquisarPassageiros(){
	PassageiroFidelizado p;
	int cont=0, op=0;
	FILE *arq = AbrirArquivo("Passageiro.dat","rb");
	cor(3);
	printf("\t\t\t -------------------------------------\n");
	printf("\t\t\t|    PESQUISAR/ALTERAR PASSAGEIROS    |\n");
	printf("\t\t\t -------------------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		cont++;
	}
	fclose(arq);
	if(cont==0){

		printf("Ainda não existem passageiros cadastrados. Por favor, cadastre um passageiro.\n");
		printf("\n");
		do
		{
			cor(3);printf("[1] ");cor(1);
			printf("Voltar\n" );
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu2();

	}else{
		char cpf[30];
		int op=0;
		PassageiroFidelizado p;
		PassageiroFidelizado *p1 = malloc(sizeof(PassageiroFidelizado));
		int cont=0, indice=-1;

		__fpurge(stdin);
		printf("Digite o CPF do passageiro: \n");
		scanf("%[^\n]", cpf);

		FILE *arq = AbrirArquivo("Passageiro.dat","rb");

		while(fread(&p, sizeof(p),1, arq)==1){
			strcpy(p1[cont].nome,p.nome);
			strcpy(p1[cont].RG,p.RG);
			strcpy(p1[cont].CPF,p.CPF);
			strcpy(p1[cont].telefone,p.telefone);
			strcpy(p1[cont].email,p.email);
			strcpy(p1[cont].contatoEmergencia,p.contatoEmergencia);
			p1[cont].dtNascimento.dia = p.dtNascimento.dia;
			p1[cont].dtNascimento.mes = p.dtNascimento.mes;
			p1[cont].dtNascimento.ano = p.dtNascimento.ano;
			if (strcmp(p1[cont].CPF,cpf)==0)
			{
				indice = cont;
			}

			cont++;
			p1 = realloc(p1,(cont+1)*sizeof(PassageiroFidelizado));
		}
		if (indice!=-1){
			printf("Nome: %s\n", p1[indice].nome);
			printf("RG: %s\n", p1[indice].RG);
			printf("CPF: %s\n", p1[indice].CPF);
			printf("Telefone: %s\n", p1[indice].telefone);
			printf("Email: %s\n", p1[indice].email);
			printf("Contato de emergencia : %s\n", p1[indice].contatoEmergencia);
			printf("Data de nascimento: %d/%d/%d\n\n", p1[indice].dtNascimento.dia, p1[indice].dtNascimento.mes, p1[indice].dtNascimento.ano);
			do
			{
				cor(3);printf("[1] ");cor(1);
				printf("Alterar o passageiro\n");
				cor(3);printf("[2] ");cor(1);
				printf("Voltar\n");
				printf("Escolha: ");
				scanf("%d", &op);
			} while (op!=1 && op!=2);
			if (op==2)
				InterfaceMenu2();
			else{
				system("clear");
				int x=0;
				do{
					__fpurge(stdin);
					printf("Digite o código do passageiro: ");
					scanf("%[^\n]",p1[indice].codPassageiro);
					x = VerificarCodPassageiro(p1[indice].codPassageiro);
					if (x==1)
						printf("O código digitado já pertence a outro passageiro!\n");
				}while (x==1);
				__fpurge(stdin);
				printf("Digite o nome do passageiro: ");
				scanf("%[^\n]", p1[indice].nome);
				__fpurge(stdin);
				printf("Digite o RG do passageiro: ");
				scanf("%[^\n]", p1[indice].RG);
				__fpurge(stdin);
				printf("Digite o CPF do passageiro: ");
				scanf("%[^\n]", p1[indice].CPF);
				__fpurge(stdin);
				printf("Digite o telefone do passageiro: ");
				scanf("%[^\n]", p1[indice].telefone);
				__fpurge(stdin);
				printf("Digite o email do passageiro: ");
				scanf("%[^\n]", p1[indice].email);
				__fpurge(stdin);
				printf("Digite o contato de emergência do passageiro (opcional): ");
				scanf("%[^\n]", p1[indice].contatoEmergencia);
				__fpurge(stdin);
				printf("Digite o dia de nascimento do passageiro: ");
				scanf("%d", &p1[indice].dtNascimento.dia);
				__fpurge(stdin);
				printf("Digite o mes de nascimento do passageiro: ");
				scanf("%d", &p1[indice].dtNascimento.mes);
				__fpurge(stdin);
				printf("Digite o ano de nascimento do passageiro: ");
				scanf("%d", &p1[indice].dtNascimento.ano);

				FILE *arqPassageiros = AbrirArquivo("Passageiro.dat","wb");
				InserirPassageirosNoArquivo(p1, arqPassageiros, cont);
				fclose(arqPassageiros);
				InterfaceMenu2();
			}
		}else{
			printf("Passageiro não encontrado!\n");
			do
			{
				cor(3);printf("[1] ");cor(1);
				printf("Voltar\n");
				printf("Escolha a opção\n");
				scanf("%d", &op);
			} while (op!=1);
			InterfaceMenu2();
		}

		fclose(arq);
		free(p1);
	}
}

void PesquisarFuncionarios(){
	Funcionario p;
	int cont=0, op=0;
	FILE *arq = AbrirArquivo("Funcionario.dat","rb");
	cor(3);
	printf("\t\t\t --------------------------------------\n");
	printf("\t\t\t|    PESQUISAR/ALTERAR FUNCIONÁRIOS    |\n");
	printf("\t\t\t --------------------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		cont++;
	}
	fclose(arq);
	if(cont==0){

		printf("Ainda não existem funcionários cadastrados. Por favor, cadastre um funcionario.\n");
		printf("\n");
		do
		{
			cor(3);printf("[1] ");cor(1);
			printf("Voltar\n" );
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu2();

	}else{

		char matricula[30];
		int op=0;
		Funcionario f;
		Funcionario *f1 = malloc(sizeof(Funcionario));
		int cont=0, indice=-1;

		__fpurge(stdin);
		printf("Digite a matricula do funcionario: ");
		scanf("%[^\n]", matricula);

		FILE *arq = AbrirArquivo("Funcionario.dat","rb");

		while(fread(&f, sizeof(f),1, arq)==1){
			strcpy(f1[cont].nome,f.nome);
			strcpy(f1[cont].matricula,f.matricula);
			strcpy(f1[cont].cargo,f.cargo);
			if (strcmp(f1[cont].matricula,matricula)==0){
				indice = cont;
			}

			cont++;
			f1 = realloc(f1,(cont+1)*sizeof(Funcionario));
		}
		if(indice!=-1){
			printf("Nome: %s\n", f1[indice].nome);
			printf("Matricula: %s\n", f1[indice].matricula);
			printf("Cargo: %s\n\n", f1[indice].cargo);
			do{
				cor(3);printf("[1] ");cor(1);
				printf("Alterar o funcionario\n");
				cor(3);printf("[2] ");cor(1);
				printf("Voltar\n");
				printf("Escolha: ");
				scanf("%d", &op);
			} while (op!=1 && op!=2);
			if (op==2)
				InterfaceMenu2();
			else{
				system("clear");
				__fpurge(stdin);
				printf("Digite o nome do funcionario: ");
				scanf("%[^\n]", f1[indice].nome);
				__fpurge(stdin);
				int x=0;
				do{
					__fpurge(stdin);
					printf("Digite a matricula do funcionario: ");
					scanf("%[^\n]", f1[indice].matricula);
					x = VerificarMatFuncionario(f1[indice].matricula);
					if (x==1)
						printf("A matrícula digitada já pertence a outro funcionário!\n");
				}while (x==1);

				__fpurge(stdin);
				printf("Digite o cargo do funcionario: ");
				scanf("%[^\n]", f1[indice].cargo);

				FILE *arqFuncionarios = AbrirArquivo("Funcionario.dat","wb");
				InserirFuncionariosNoArquivo(f1, arqFuncionarios, cont);
				fclose(arqFuncionarios);
				InterfaceMenu2();
			}
		}else{
			printf("Funcionário não encontrado!\n");
			do{
				cor(3);printf("[1] ");cor(1);
				printf("Voltar\n");
				printf("Escolha: ");
				scanf("%d", &op);
			} while(op!=1);
			InterfaceMenu2();
		}
		fclose(arq);
		free(f1);
	}
}

#endif
