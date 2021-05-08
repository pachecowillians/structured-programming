// ---------------------------------- FUNC. CADASTRO -------------------------------------------
// Funções de cadastro e inserção de dados nos arquivos

#ifndef CADASTRO_H
#define CADASTRO_H

void CadastrarTrechos(){
	Aeroporto p;
	int cont=0, op=0;
	FILE *arq = AbrirArquivo("Aeroporto.dat","rb");

	cor(3);
	printf("\t\t\t ---------------------------\n");
	printf("\t\t\t|    CADASTRO DE TRECHOS    |\n");
	printf("\t\t\t ---------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		cont++;
	}
	fclose(arq);
	if(cont==0){

		printf("Ainda não existem aeroportos cadastrados. Por favor, cadastre um aeroporto.\n");
		printf("\n");
		do
		{
			cor(3);
			printf("[1] " );
			cor(1);
			printf("Voltar\n");
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu2();

	}else{

		Trecho p;
		char resp;
		int x=0;
		int cont=0, op;
		Aeroporto p1;
		FILE *arq;
		do{
			__fpurge(stdin);
			printf("Digite o código do trecho: ");
			scanf("%d", &p.codTrecho);
			x = VerificarCodTrecho(p.codTrecho);
			if (x==1)
				printf("O código digitado já pertence a outro trecho!\n");
		}while (x==1);

		arq = AbrirArquivo("Aeroporto.dat","rb");
		printf("\n\t       -------Aeroportos disponíveis para origem-------\n");
		while(fread(&p1, sizeof(p1),1, arq)==1){
			printf("\nCódigo: %s\n", p1.codAeroporto);
			printf("Nome: %s\n", p1.nomeAeroporto);
			printf("Cidade: %s\n", p1.cidade);
			printf("Estado: %s\n\n", p1.estado);
			cont++;
		}

		if (cont==0)
			printf("Não existem Aeroportos cadastrados!\n");
		fclose(arq);

		__fpurge(stdin);
		do{
			printf("Digite o código do aeroporto de origem: ");
			scanf("%[^\n]", p.aeroportoOrigem);
			__fpurge(stdin);

			if(VerificarCodAeroporto(p.aeroportoOrigem)==0){
				printf("\nNão existem aeroportos com esse código! \n");
			}
		}while(VerificarCodAeroporto(p.aeroportoOrigem)==0);

		printf("\n");

		cont=0;
		arq = AbrirArquivo("Aeroporto.dat","rb");
		printf("\n\t       -------Aeroportos disponíveis para destino-------\n");
		while(fread(&p1, sizeof(p1),1, arq)==1){
			printf("\nCódigo: %s\n", p1.codAeroporto);
			printf("Nome: %s\n", p1.nomeAeroporto);
			printf("Cidade: %s\n", p1.cidade);
			printf("Estado: %s\n\n", p1.estado);
			cont++;
		}

		if (cont==0)
			printf("Não existem aeroportos cadastrados!\n");
		fclose(arq);

		do{
			printf("Digite o código do aeroporto de destino: ");
			scanf("%[^\n]", p.aeroportoDestino);
			__fpurge(stdin);

			if(VerificarCodAeroporto(p.aeroportoDestino)==0){
				printf("\nNão existem aeroportos com esse código! \n");
			}
		}while(VerificarCodAeroporto(p.aeroportoDestino)==0);

		__fpurge(stdin);
		printf("Digite a quantidade de milhas desse trecho: ");
		scanf("%f", &p.milhas);

		__fpurge(stdin);
		printf("Digite o local de origem do trecho: ");
		scanf("%[^\n]", p.origem);

		__fpurge(stdin);
		printf("Digite o local de destino do trecho: ");
		scanf("%[^\n]", p.destino);

		FILE *arqTrechos = fopen("Trecho.dat","ab");
		InserirTrechosNoArquivo(&p, arqTrechos, 1);
		fclose(arqTrechos);
		InterfaceMenu2();
	}
}

void CadastrarRotas(){
	Trecho *t1 = malloc(sizeof(Trecho));
	Trecho t;

	int cont=0, op=0;
	FILE *arq = AbrirArquivo("Trecho.dat","rb");

	cor(3);
	printf("\t\t\t -------------------------\n");
	printf("\t\t\t|    CADASTRO DE ROTAS    |\n");
	printf("\t\t\t -------------------------\n\n");
	cor(1);

	while(fread(&t, sizeof(t),1, arq)==1){
		t1[cont] = t;
		t1 = realloc(t1,(cont+2)*sizeof(Trecho));
		cont++;
	}
	fclose(arq);
	if(cont==0){

		printf("Ainda não existem trechos cadastrados. Por favor, cadastre um trecho.\n");
		printf("\n");
		do
		{
			cor(3);
			printf("[1] " );
			cor(1);
			printf("Voltar\n");
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu2();

	}else{

		Rota p;
		RotaTrecho rt;
		Poltrona *polt;
		char respAdicionar;
		int x=0, i=0, contPoltrona=0, tamRotaTrecho=0;

		FILE *arq = AbrirArquivo("RotaTrecho.dat","rb");
		i=0;
		while(fread(&rt, sizeof(rt),1, arq)==1){
			i++;
		}
		tamRotaTrecho = i;
		fclose(arq);
		i=0;

		do{
			__fpurge(stdin);
			printf("Digite o código da rota: ");
			scanf("%d", &p.codRota);
			x = VerificarCodRota(p.codRota);
			if (x==1)
				printf("O código digitado já pertence a outra rota!\n");
		}while (x==1);

		__fpurge(stdin);
		printf("Digite o número de poltronas disponíveis nessa rota: ");
		scanf("%d", &p.numPoltrona);

		do{
			__fpurge(stdin);
			cor(3);
			printf("\n[1] ");
			cor(1);
			printf("Dia útil\n");
			cor(3);
			printf("[2] ");
			cor(1);
			printf("Feriado nacional\n");
			cor(3);
			printf("[3] ");
			cor(1);
			printf("Final de semana\n");
			printf("Selecione o tipo de dia da viagem: ");
			scanf("%d", &p.tipoDia);
			if(p.tipoDia>3 || p.tipoDia<1){
				printf("O número digitado não corresponde as opções fornecidas!\n");
			}
		}while(p.tipoDia>3 || p.tipoDia<1);


		__fpurge(stdin);
		printf("Intervalo de retorno em dias: ");
		scanf("%d", &p.retorno);

		do
		{
			printf("\n\t-------Trechos disponíveis-------\n");
			PrintarTrechosArquivo(-1);
			do{
				__fpurge(stdin);
				printf("Digite o código do trecho na ordem que o avião vai passar por ele: ");
				scanf("%d", &rt.codTrecho);

				if(VerificarCodTrecho(rt.codTrecho)==0){
					printf("\nNão existem trechos com esse código! \n");
				}
			}while(VerificarCodTrecho(rt.codTrecho)==0);

			__fpurge(stdin);
			if(i==0){
				for(int j=0; j<cont; j++){
					if(t1[j].codTrecho == rt.codTrecho){
						strcpy(p.origem,t1[j].origem);
					}
				}
			}

			rt.codRota = p.codRota;
			polt = malloc(p.numPoltrona*sizeof(Poltrona));
			for (int j = 0; j < p.numPoltrona; ++j){
				polt[j].PosRotaTrecho=tamRotaTrecho;
				polt[j].numPoltrona = j+1;
				polt[j].ocupada = 0;
				contPoltrona++;
			}

			do{
				__fpurge(stdin);
				printf("Digite a hora de saída da origem: ");
				scanf("%d", &rt.hrInicio.hora);
				if(rt.hrInicio.hora>24 || rt.hrInicio.hora<0){
					printf("O número digitado não corresponde as horas!\n");
				}
			}while(rt.hrInicio.hora>24 || rt.hrInicio.hora<0);

			do{
				__fpurge(stdin);
				printf("Digite os minutos de saída da origem: ");
				scanf("%d", &rt.hrInicio.min);
				if(rt.hrInicio.min>60 || rt.hrInicio.min<0){
					printf("O número digitado não corresponde aos minutos!\n");
				}
			}while(rt.hrInicio.min>60 || rt.hrInicio.min<0);

			do{
				__fpurge(stdin);
				printf("Digite a hora de chegada no destino: ");
				scanf("%d", &rt.hrFim.hora);
				if(rt.hrFim.hora>24 || rt.hrFim.hora<0){
					printf("O número digitado não corresponde as horas!\n");
				}
			}while(rt.hrFim.hora>24 || rt.hrFim.hora<0);

			do{
				__fpurge(stdin);
				printf("Digite os minutos de chegada no destino: ");
				scanf("%d", &rt.hrFim.min);
				if(rt.hrFim.min>60 || rt.hrFim.min<0){
					printf("O número digitado não corresponde aos minutos!\n");
				}
			}while(rt.hrFim.min>60 || rt.hrFim.min<0);

			char resp;
			__fpurge(stdin);
			printf("O voo irá durar apenas um dia?(S/N): ");
			scanf("%c", &resp);
			rt.diario = 1;
			if (resp=='N')
			{
				rt.diario = 0;
                do{ //tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o dia de saída da origem: ");
                	scanf("%d", &rt.dtInicio.dia);
                	if(rt.dtInicio.dia>31 || rt.dtInicio.dia<0){
                		printf("O número digitado não corresponde aos dias!\n");
                	}
                }while(rt.dtInicio.dia>31 || rt.dtInicio.dia<0);

                do{//tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o mês de saída da origem: ");
                	scanf("%d", &rt.dtInicio.mes);
                	if(rt.dtInicio.mes>12 || rt.dtInicio.mes<0){
                		printf("O número digitado não corresponde aos meses!\n");
                	}
                }while(rt.dtInicio.mes>12 || rt.dtInicio.mes<0);

                __fpurge(stdin);
                printf("Digite o ano de saída da origem: ");
                scanf("%d", &rt.dtInicio.ano);

                do{//tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o dia de chegada no destino: ");
                	scanf("%d", &rt.dtFim.dia);
                	if(rt.dtFim.dia>31 || rt.dtFim.dia<0){
                		printf("O número digitado não corresponde aos dias!\n");
                	}
                }while(rt.dtFim.dia>31 || rt.dtFim.dia<0);

                do{//tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o mês de chegada no destino: ");
                	scanf("%d", &rt.dtFim.mes);
                	if(rt.dtFim.mes>12 || rt.dtFim.mes<0){
                		printf("O número digitado não corresponde aos meses!\n");
                	}
                }while(rt.dtFim.mes>12 || rt.dtFim.mes<0);

                __fpurge(stdin);
                printf("Digite o ano de chegada no destino: ");
                scanf("%d", &rt.dtFim.ano);

            }else{

                do{//tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o dia da viagem: ");
                	scanf("%d", &rt.dtInicio.dia);
                	if(rt.dtInicio.dia>31 || rt.dtInicio.dia<0){
                		printf("O número digitado não corresponde aos dias!\n");
                	}
                }while(rt.dtInicio.dia>31 || rt.dtInicio.dia<0);

                do{//tratamento de erros
                	__fpurge(stdin);
                	printf("Digite o mês da viagem: ");
                	scanf("%d", &rt.dtInicio.mes);
                	if(rt.dtInicio.mes>12 || rt.dtInicio.mes<0){
                		printf("O número digitado não corresponde aos meses!\n");
                	}
                }while(rt.dtInicio.mes>12 || rt.dtInicio.mes<0);

                __fpurge(stdin);
                printf("Digite o ano da viagem: ");
                scanf("%d", &rt.dtInicio.ano);

                rt.dtFim.dia = rt.dtInicio.dia;
                rt.dtFim.mes = rt.dtInicio.mes;
                rt.dtFim.ano = rt.dtInicio.ano;
            }

            FILE *arqPoltrona = fopen("Poltrona.dat","ab");
            InserirPoltronaNoArquivo(polt, arqPoltrona, contPoltrona);
            fclose(arqPoltrona);

            FILE *arqRotaTrecho = fopen("RotaTrecho.dat","ab");
            InserirRotasTrechosNoArquivo(&rt, arqRotaTrecho, 1);
            fclose(arqRotaTrecho);

            __fpurge(stdin);
            printf("Deseja adicionar outro trecho?(S/N): ");
            scanf("%c", &respAdicionar);
            __fpurge(stdin);
            i++;
        } while (respAdicionar!='N');


        for(int j=0; j<cont; j++){
        	if(t1[j].codTrecho == rt.codTrecho){
        		strcpy(p.destino,t1[j].destino);
        	}
        }


        p.numTrechos = i;

        FILE *arqRota = fopen("Rota.dat","ab");
        InserirRotasNoArquivo(&p, arqRota, 1);
        fclose(arqRota);

        InterfaceMenu2();
    }
}

void CadastrarFuncionarios(){
	Funcionario p;
	cor(3);
	printf("\t\t\t --------------------------------\n");
	printf("\t\t\t|    CADASTRO DE FUNCIONÁRIOS    |\n");
	printf("\t\t\t --------------------------------\n\n");
	cor(1);
	__fpurge(stdin);
	printf("Digite o nome do funcionário: ");
	scanf("%[^\n]", p.nome);
	__fpurge(stdin);
	int x=0;
	do{
		__fpurge(stdin);
		printf("Digite a matrícula do funcionário: ");
		scanf("%[^\n]", p.matricula);
		x = VerificarMatFuncionario(p.matricula);
		if (x==1)
			printf("A matrícula digitada já pertence a outro funcionário!\n");
	}while (x==1);

	__fpurge(stdin);
	printf("Digite o cargo do funcionário: ");
	scanf("%[^\n]", p.cargo);

	FILE *arqFuncionarios = fopen("Funcionario.dat","ab");
	InserirFuncionariosNoArquivo(&p, arqFuncionarios, 1);
	fclose(arqFuncionarios);
	InterfaceMenu2();
}

void CadastrarAeroportos(){
	Aeroporto d;
	int x=0;
	cor(3);
	printf("\t\t\t ------------------------------\n");
	printf("\t\t\t|    CADASTRO DE AEROPORTOS    |\n");
	printf("\t\t\t ------------------------------\n\n");
	cor(1);
	do
	{
		__fpurge(stdin);
		printf("Digite o código do Aeroporto: ");
		scanf("%[^\n]", d.codAeroporto);
		x = VerificarCodAeroporto(d.codAeroporto);
		if (x==1)
			printf("O código digitado já pertence a outro Aeroporto!\n");
	} while (x==1);
	__fpurge(stdin);
	printf("Digite o nome do Aeroporto: ");
	scanf("%[^\n]", d.nomeAeroporto);
	__fpurge(stdin);
	printf("Digite o nome da cidade: ");
	scanf("%[^\n]", d.cidade);
	__fpurge(stdin);
	printf("Digite o nome do estado: ");
	scanf("%[^\n]", d.estado);

	FILE *arqAeroporto = AbrirArquivo("Aeroporto.dat","ab");
	InserirAeroportoNoArquivo(&d,arqAeroporto,1);
	fclose(arqAeroporto);
	InterfaceMenu2();
}

void CadastrarPassageiros(){
	PassageiroFidelizado p;
	int x=0;
	cor(3);
	printf("\t\t\t -------------------------------\n");
	printf("\t\t\t|    CADASTRO DE PASSAGEIROS    |\n");
	printf("\t\t\t -------------------------------\n\n");
	cor(1);

	do
	{
		__fpurge(stdin);
		printf("Digite o código do passageiro: ");
		scanf("%[^\n]", p.codPassageiro);
		x = VerificarCodPassageiro(p.codPassageiro);
		if (x==1)
			printf("O código digitado já pertence a outro passageiro!\n");
	} while (x==1);
	__fpurge(stdin);
	printf("Digite o nome do passageiro: ");
	scanf("%[^\n]", p.nome);
	__fpurge(stdin);
	printf("Digite o RG do passageiro: ");
	scanf("%[^\n]", p.RG);
	__fpurge(stdin);
	printf("Digite o CPF do passageiro: ");
	scanf("%[^\n]", p.CPF);
	__fpurge(stdin);
	printf("Digite o telefone do passageiro: ");
	scanf("%[^\n]", p.telefone);
	__fpurge(stdin);
	printf("Digite o email do passageiro: ");
	scanf("%[^\n]", p.email);
	__fpurge(stdin);
	printf("Digite o contato de emergência do passageiro (opcional): ");
	scanf("%[^\n]", p.contatoEmergencia);
	__fpurge(stdin);
	printf("Digite o dia de nascimento do passageiro: ");
	scanf("%d", &p.dtNascimento.dia);
	__fpurge(stdin);
	printf("Digite o mes de nascimento do passageiro: ");
	scanf("%d", &p.dtNascimento.mes);
	__fpurge(stdin);
	printf("Digite o ano de nascimento do passageiro: ");
	scanf("%d", &p.dtNascimento.ano);

	FILE *arqPassageiros = fopen("Passageiro.dat","ab");
	InserirPassageirosNoArquivo(&p, arqPassageiros, 1);
	fclose(arqPassageiros);
	InterfaceMenu2();
}

#endif
