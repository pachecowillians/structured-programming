// ---------------------------------- FUNC. LISTAR -------------------------------------------
// Funções de Listar dados presentes nos arquivos

#ifndef LISTAR_H
#define LISTAR_H

void ListarRotasArquivo(){
	Rota *r1 = malloc(sizeof(Rota));
	Rota r;

	int cod=-1 , op, i=0;
	RotaTrecho rt;
	FILE *arq = AbrirArquivo("Rota.dat","rb");

	cor(3);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|    LISTANDO ROTAS    |\n");
	printf("\t\t\t ----------------------\n\n");
	cor(1);

	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	fclose(arq);

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;
	while(fread(&rt, sizeof(rt),1, arq)==1){
		if(cod==-1){
			cor(4);printf("Rota: ");cor(1);
			printf("%s X %s \n\n", r1[i].origem, r1[i].destino);
			printf("Código: %d\n", r1[i].codRota);
			printf("Número de poltrona da rota: %d\n", r1[i].numPoltrona);
			printf("Número de trechos da rota: %d\n\n", r1[i].numTrechos);
			cor(3);
			printf("Trechos desta rota:\n");
			cor(1);
			cod=rt.codRota;
		}
		else if(rt.codRota != cod){
			i++;
			cor(4);printf("Rota: ");cor(1);
			printf("%s X %s \n\n", r1[i].origem, r1[i].destino);
			printf("Código: %d\n", r1[i].codRota);
			printf("Número de poltrona da rota: %d\n", r1[i].numPoltrona);
			printf("Número de trechos da rota: %d\n\n", r1[i].numTrechos);
			cor(3);
			printf("Trechos desta rota:\n");
			cor(1);
			cod=rt.codRota;
		}
		PrintarTrechosArquivo(rt.codTrecho);
	}
	if (cod==-1)
		printf("Não existem rotas cadastradas!\n");

	printf("\n");
	do{
		__fpurge(stdin);
		cor(3);
		printf("[1] ");
		cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1);
	fclose(arq);
	free(r1);
	InterfaceMenu2();
}

void ListarCidadeArquivo(int opcao){
	system("clear");
	Rota r;
	Trecho t;
	RotaTrecho rt;
	Rota *r1 = malloc(sizeof(Rota));
	Trecho *t1 = malloc(sizeof(Trecho));
	int cod=0 , op, i=0, contTrecho=0;

	cor(3);
	printf("\t\t\t ------------------------\n");
	printf("\t\t\t|    LISTANDO CIDADES    |\n");
	printf("\t\t\t ------------------------\n\n");
	cor(1);

	FILE *arq = AbrirArquivo("Rota.dat","rb");
	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	fclose(arq);

	arq = AbrirArquivo("Trecho.dat","rb");
	i=0;
	while(fread(&t, sizeof(t),1, arq)==1){
		t1[i] = t;
		t1 = realloc(t1,(i+2)*sizeof(Trecho));
		i++;
	}
	contTrecho = i;
	fclose(arq);

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;
	int *vetCidades = malloc(sizeof(int));
	int contCidade=0;

	while(fread(&rt, sizeof(rt),1, arq)==1){
		for(i=0; i<contTrecho; i++){
			if(rt.codTrecho == t1[i].codTrecho){
                if(BuscaVetorCidades(vetCidades, contCidade, i)==0){ //Garante que ele mostre apenas as cidades que ainda não foram mostradas
                	if(contCidade==0)
                		printf("Cidades: \n\n");
                	if(opcao == 1)
                		printf("%s\n", t1[i].origem);
                	else
                		printf("%s\n", t1[i].destino);
                	vetCidades[contCidade] = i;
                }
                contCidade++;
                vetCidades = realloc(vetCidades, (contCidade+1)*sizeof(int));
            }
        }
        cod++;
    }

    if (cod==0)
    {
    	printf("Não existem rotas com cidades cadastradas!\n");
    }
    printf("\n");
    do{
    	__fpurge(stdin);
    	cor(3);
    	printf("[1] ");
    	cor(1);
    	printf("Voltar\n");
    	printf("Escolha: ");
    	scanf("%d", &op);
    } while (op!=1);
    fclose(arq);
    free(r1);
    free(t1);
    InterfaceMenu2();
}

void PrintarCidadeArquivo(int opcao, char nome[50]){
	system("clear");
	Rota r;
	Trecho t;
	RotaTrecho rt;
	int cod=0 , op, i=0, contTrecho=0;
	Rota *r1 = malloc(sizeof(Rota));
	Trecho *t1 = malloc(sizeof(Trecho));

	FILE *arq = AbrirArquivo("Rota.dat","rb");
	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	fclose(arq);

	arq = AbrirArquivo("Trecho.dat","rb");
	i=0;
	while(fread(&t, sizeof(t),1, arq)==1){
		t1[i] = t;
		t1 = realloc(t1,(i+2)*sizeof(Trecho));
		i++;
	}
	contTrecho = i;
	fclose(arq);

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;
	int *vetCidades = malloc(sizeof(int));
	int contCidade=0;
	while(fread(&rt, sizeof(rt),1, arq)==1){
		for(i=0; i<contTrecho; i++){
			if(rt.codTrecho == t1[i].codTrecho){
                if(BuscaVetorCidades(vetCidades, contCidade, i)==0){ //Garante que ele mostre apenas as cidades que ainda não foram mostradas
                	if(contCidade==0){
                		if(opcao==1){
                			cor(3);
                			printf("\t\t\t -------------------------\n");
                			printf("\t\t\t|    SELECIONAR ORIGEM    |\n");
                			printf("\t\t\t -------------------------\n\n");
                			cor(1);
                			printf("Cidades Origem: \n\n");
                		}
                		if(opcao==2){
                			cor(3);
                			printf("\t\t\t --------------------------\n");
                			printf("\t\t\t|    SELECIONAR DESTINO    |\n");
                			printf("\t\t\t --------------------------\n\n");
                			cor(1);
                			printf("Cidades Destino: \n\n");
                		}

                	}
                	if(opcao == 1){
                		printf("%s\n", t1[i].origem);
                	}
                	else{
                		if(strcmp(nome, t1[i].destino)!=0)
                			printf("%s\n", t1[i].destino);
                	}
                	vetCidades[contCidade] = i;
                }
                contCidade++;
                vetCidades = realloc(vetCidades, (contCidade+1)*sizeof(int));
            }
        }
        cod++;
    }
    if (cod==0)
    	printf("Não existem rotas com cidades cadastradas!\n");

    free(r1);
    free(t1);
    fclose(arq);
}

void ListarPassageirosArquivo(){
	PassageiroFidelizado p;
	int cont=0, op;
	FILE *arq = AbrirArquivo("Passageiro.dat","rb");
	cor(3);
	printf("\t\t\t ----------------------------\n");
	printf("\t\t\t|    LISTANDO PASSAGEIROS    |\n");
	printf("\t\t\t ----------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		printf("Código: %s\n", p.codPassageiro);
		printf("Nome: %s\n", p.nome);
		printf("RG: %s\n", p.RG);
		printf("CPF: %s\n", p.CPF);
		printf("Telefone: %s\n", p.telefone);
		printf("Email: %s\n", p.email);
		printf("Contato de emergencia: %s\n", p.contatoEmergencia);
		printf("Data de nascimento: %d/%d/%d\n\n", p.dtNascimento.dia, p.dtNascimento.mes, p.dtNascimento.ano);
		cor(3);
		printf("- - - - - - - - - - - - - - - - - - - - - - - \n");
		cor(1);
		cont++;
		printf("\n");
	}
	if(cont==0)
		printf("Não existem passageiros cadastrados!\n\n");
	do{
		cor(3);
		printf("[1] ");
		cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1);
	fclose(arq);
	InterfaceMenu2();
}

void PrintarPassageirosArquivo(){
	PassageiroFidelizado p;
	int cont=0, op;
	FILE *arq = AbrirArquivo("Passageiro.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		printf("Código: %s\n", p.codPassageiro);
		printf("Nome: %s\n", p.nome);
		printf("RG: %s\n", p.RG);
		printf("CPF: %s\n", p.CPF);
		printf("Telefone: %s\n", p.telefone);
		printf("Email: %s\n", p.email);
		printf("Contato de emergencia: %s\n", p.contatoEmergencia);
		printf("Data de nascimento: %d/%d/%d\n", p.dtNascimento.dia, p.dtNascimento.mes, p.dtNascimento.ano);
		cont++;
	}
	if(cont==0)
		printf("Não existem passageiros cadastrados!\n\n");
	fclose(arq);
}

void ListarTrechosArquivo(){
	Aeroporto a;
	Aeroporto *a1 = malloc(sizeof(Aeroporto));
	FILE *arq = AbrirArquivo("Aeroporto.dat","rb");
	int i=0, posO ,posD;
	while(fread(&a, sizeof(a),1, arq)==1){
		a1[i] = a;
		a1 = realloc(a1, (i+2)*sizeof(Aeroporto));
		i++;
	}
	fclose(arq);

	Trecho p;
	int cont=0, op;
	arq = AbrirArquivo("Trecho.dat","rb");
	cor(3);
	printf("\t\t\t ------------------------\n");
	printf("\t\t\t|    LISTANDO TRECHOS    |\n");
	printf("\t\t\t ------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		
		for (int j = 0; j < i; ++j)
		{

			if(strcmp(p.aeroportoOrigem, a1[j].codAeroporto)==0)
				posO = j;
			if(strcmp(p.aeroportoDestino, a1[j].codAeroporto)==0)
				posD = j;
		}

		printf("Código: %d\n", p.codTrecho);
		printf("Aeroporto de origem: %s\n", a1[posO].nomeAeroporto);
		printf("Aeroporto de destino: %s\n", a1[posD].nomeAeroporto);
		printf("Milhas: %.2f\n", p.milhas);
		printf("Origem: %s\n", p.origem);
		printf("Destino: %s\n\n", p.destino);
		cor(3);
		printf("- - - - - - - - - - - - - - - - - - - - - - - \n");
		cor(1);
		cont++;
		printf("\n");
	}
	if(cont==0)
		printf("Não existem trechos cadastrados!\n\n");
	do{
		cor(3);
		printf("[1] ");
		cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1);
	fclose(arq);
	InterfaceMenu2();
}

void PrintarTrechosArquivo(int cod){

	Aeroporto a;
	Aeroporto *a1 = malloc(sizeof(Aeroporto));
	FILE *arq = AbrirArquivo("Aeroporto.dat","rb");
	int i=0, posO ,posD;
	while(fread(&a, sizeof(a),1, arq)==1){
		a1[i] = a;
		a1 = realloc(a1, (i+2)*sizeof(Aeroporto));
		i++;
	}
	fclose(arq);
	Trecho p;
	int cont=0, op;
	arq = AbrirArquivo("Trecho.dat","rb");


	while(fread(&p, sizeof(p),1, arq)==1){
		if(cod!=-1){
			if(cod == p.codTrecho){

				for (int j = 0; j < i; ++j)
				{

					if(strcmp(p.aeroportoOrigem, a1[j].codAeroporto)==0)
						posO = j;
					if(strcmp(p.aeroportoDestino, a1[j].codAeroporto)==0)
						posD = j;
				}

				printf("\nCódigo: %d\n", p.codTrecho);
				printf("Aeroporto de origem: %s\n", a1[posO].nomeAeroporto);
				printf("Aeroporto de destino: %s\n", a1[posD].nomeAeroporto);

				printf("Milhas: %.2f\n", p.milhas);
				printf("Origem: %s\n", p.origem);
				printf("Destino: %s\n", p.destino);
				cont++;
				printf("\n");
			}
		}else{
			for (int j = 0; j < i; ++j)
			{

				if(strcmp(p.aeroportoOrigem, a1[j].codAeroporto)==0)
					posO = j;
				if(strcmp(p.aeroportoDestino, a1[j].codAeroporto)==0)
					posD = j;
			}
			printf("\nCódigo: %d\n", p.codTrecho);
			printf("Aeroporto de origem: %s\n", a1[posO].nomeAeroporto);
			printf("Aeroporto de destino: %s\n",  a1[posD].nomeAeroporto);
			printf("Milhas: %.2f\n", p.milhas);
			printf("Origem: %s\n", p.origem);
			printf("Destino: %s\n", p.destino);
			cont++;
			printf("\n");
		}
	}
	if(cont==0)
		printf("Não existem trechos cadastrados!\n\n");
	fclose(arq);
}

void ListarFuncionariosArquivo(){
	Funcionario p;
	int cont=0, op;
	FILE *arq = AbrirArquivo("Funcionario.dat","rb");
	cor(3);
	printf("\t\t\t -----------------------------\n");
	printf("\t\t\t|    LISTANDO FUNCIONÁRIOS    |\n");
	printf("\t\t\t -----------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		printf("Nome do funcionário: %s\n", p.nome);
		printf("Matrícula do funcionário: %s\n", p.matricula);
		printf("Cargo do funcionário: %s\n\n", p.cargo);
		cor(3);
		printf("- - - - - - - - - - - - - - - - - - - - - - - \n\n");
		cor(1);
		cont++;
	}
	if(cont==0)
		printf("Não existem funcionários cadastrados!\n\n");
	do{
		cor(3);
		printf("[1] ");
		cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	}while (op!=1);
	InterfaceMenu2();
}

void ListarAeroportosArquivo(){
	Aeroporto p;
	int cont=0, op;
	FILE *arq = AbrirArquivo("Aeroporto.dat","rb");
	cor(3);
	printf("\t\t\t ---------------------------\n");
	printf("\t\t\t|    LISTANDO AEROPORTOS    |\n");
	printf("\t\t\t ---------------------------\n\n");
	cor(1);

	while(fread(&p, sizeof(p),1, arq)==1){
		printf("Código: %s\n", p.codAeroporto);
		printf("Nome: %s\n", p.nomeAeroporto);
		printf("Cidade: %s\n", p.cidade);
		printf("Estado: %s\n\n", p.estado);
		cor(3);
		printf("- - - - - - - - - - - - - - - - - - - - - - - \n\n");
		cor(1);
		cont++;
	}

	if (cont==0)
		printf("Não existem aeroportos cadastrados!\n\n");
	do
	{
		cor(3);
		printf("[1] ");
		cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1);
	fclose(arq);
	InterfaceMenu2();
}

void PrintarCadeirasDisponiveis(int origem, int destino){
	int disponivel =0, numCadeiras=0;
	int contP=0;
	int contRota, contRotaTrecho;
	FILE *arq;
	Rota r;
	RotaTrecho rt;
	Rota *r1 = malloc(sizeof(Trecho));
	arq = AbrirArquivo("Rota.dat","rb");
	int i=0;

	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	contRota = i;
	fclose(arq);

	RotaTrecho *rt1 = malloc(sizeof(Trecho));
	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;

	while(fread(&rt, sizeof(rt),1, arq)==1){
		rt1[i] = rt;
		rt1 = realloc(rt1,(i+2)*sizeof(RotaTrecho));
		i++;
	}
	contRotaTrecho = i;
	fclose(arq);

	for (int j=0; j< contRota;j++){
		if(r1[j].codRota==rt1[origem].codRota){
			numCadeiras=r1[j].numPoltrona;
		}
	}
	for (int j=1; j<=numCadeiras;j++){
		if(PoltronaOcupadaIntervaloTrechos(j,origem,destino)==0){
			cor(3);
			if(contP<2){
				printf("[%d]  ", j);
				if (j<10)
					printf(" ");
				if (j<100)
					printf(" ");
				contP++;
			}else if(contP==2){
				printf("    [%d]",j);
				contP++;
			}else if(contP>2){
				if (j<10)
					printf(" ");
				if (j<=100)
					printf(" ");
				printf("  [%d]",j);
				printf("\n");
				contP=0;
			}
			cor(1);
		}else{
			cor(4);
			if(contP<2){
				printf("[%d]    ", j);
				contP++;
			}else if(contP==2){
				printf("    [%d] ", j);
				contP++;
			}else if(contP>2){
				printf("   [%d]", j);
				printf("\n");
				contP=0;
			}
			cor(1);
		}
	}
}

void ListarHorarios(int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado){
	Hora hs, hc;
	Trecho t;
	RotaTrecho rt;
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));
	Trecho *t1 = malloc(sizeof(Trecho));
	int b=0;

	FILE *arq2 = AbrirArquivo("RotaTrecho.dat","rb");
	while(fread(&rt, sizeof(rt),1, arq2)==1){
		rt1[b] = rt;
		rt1 = realloc(rt1,(b+2)*sizeof(RotaTrecho));
		b++;
	}
	fclose(arq2);

	int c=0;
	FILE *arq3 = AbrirArquivo("Trecho.dat","rb");
	while(fread(&t, sizeof(t),1, arq3)==1){
		t1[c] = t;
		t1 = realloc(t1,(c+2)*sizeof(Trecho));
		c++;
	}
	fclose(arq3);

	system("clear");
	cor(3);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|       HORÁRIOS       |\n");
	printf("\t\t\t ----------------------\n\n");
	cor(1);

	for(int i=0; i<tamVetFiltrado; i++){
		hs = rt1[rtOrigemF[i]].hrInicio;
		hc = rt1[rtDestinoF[i]].hrFim;
		cor(3);
		printf("[%d] ",i+1);
		cor(1);
		printf("Horário de saída: %.2d:%.2d\n    Horário de chegada: %.2d:%.2d\n\n", hs.hora, hs.min, hc.hora, hc.min);
	}

}

#endif
