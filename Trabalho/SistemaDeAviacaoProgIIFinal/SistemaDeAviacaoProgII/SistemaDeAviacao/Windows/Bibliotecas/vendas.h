// ---------------------------------------- FUNC. VENDAS -----------------------------------
// Funções usadas para tratar, gerenciar e realizar uma venda no sistema

#ifndef VENDAS_H
#define VENDAS_H

void Etapa1(){
	int *rotaTrechoOrigem, *rotaTrechoDestino;
	int *rotaTrechoOrigemFiltrado = malloc(sizeof(int));
	int *rotaTrechoDestinoFiltrado = malloc(sizeof(int));
	rotaTrechoOrigem = malloc(1*sizeof(int));
	rotaTrechoDestino = malloc(1*sizeof(int));
	Venda v;
	int tamVet=0, tamVetFiltrado=0;

	PrintarCidadeArquivo(1,"");
	do
	{
		fflush(stdin);
		printf("\nDigite a origem: ");
		scanf("%[^\n]", v.origem);
		if (ExisteOrigem(v.origem)==0)
			printf("Origem inexistente!\n");
	} while (ExisteOrigem(v.origem)==0);


	PrintarCidadeArquivo(2, v.origem);
	do
	{
		fflush(stdin);
		printf("\nDigite o destino: ");
		scanf("%[^\n]", v.destino);
		if (ExisteDestino(v.destino)==0)
			printf("Destino inexistente!\n");
	} while (ExisteDestino(v.destino)==0);

	CriarVetorRotasOrigemDestino(v.origem, v.destino, rotaTrechoOrigem, rotaTrechoDestino, &tamVet);
	FiltrarRotasDisponiveis(rotaTrechoOrigem, rotaTrechoDestino, rotaTrechoOrigemFiltrado, rotaTrechoDestinoFiltrado, tamVet, &tamVetFiltrado);
	InterfaceVenda2(v, rotaTrechoOrigemFiltrado, rotaTrechoDestinoFiltrado, tamVetFiltrado);
}

void Etapa2(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado){
	int horario;
	Trecho t;
	Rota r;
	RotaTrecho rt;
	Trecho *t1 = malloc(sizeof(Trecho));
	Rota *r1 = malloc(sizeof(Rota));
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));
	int a=0, indicePonteiros=0, b=0;

	FILE *arq1 = AbrirArquivo("Rota.dat","rb");
	while(fread(&r, sizeof(r),1, arq1)==1){
		r1[a] = r;
		r1 = realloc(r1,(a+2)*sizeof(Rota));
		a++;
	}
	fclose(arq1);

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

	ListarHorarios(rtOrigemF, rtDestinoF, tamVetFiltrado);
	int posicaoInicio = 0, posicaoFim =0;
	do
	{
		fflush(stdin);
		printf("\nEscolha o horário: ");
		scanf("%d", &horario);
		if(horario<=0 || horario>tamVetFiltrado){
			printf("O horário escolhido não se encontra na lista!\n");
		}
	} while (horario<=0 || horario>tamVetFiltrado);

	v.hrEmbarque = rt1[rtOrigemF[horario-1]].hrInicio;
	v.dtEmbarque = rt1[rtOrigemF[horario-1]].dtInicio;
	v.hrDesembarque = rt1[rtOrigemF[horario-1]].hrFim;
	v.dtDesembarque = rt1[rtOrigemF[horario-1]].dtFim;


	posicaoInicio = horario-1;

	InterfaceVenda3(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
}

void Etapa3(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){

	cor(3);
	printf("\t\t\t -----------------------\n");
	printf("\t\t\t|       POLTRONAS       |\n");
	printf("\t\t\t -----------------------\n\n\n");
	cor(1);
	PrintarCadeirasDisponiveis(rtOrigemF[posicaoInicio],rtDestinoF[posicaoInicio]);

	do{
		fflush(stdin);
		printf("\n\nEscolha o assento: ");
		scanf("%d", &v.poltrona);
		if(PoltronaOcupadaIntervaloTrechos(v.poltrona,rtOrigemF[posicaoInicio],rtDestinoF[posicaoInicio])!=0)
			printf("A poltrona escolhida está ocupada!\n");
	}while(PoltronaOcupadaIntervaloTrechos(v.poltrona,rtOrigemF[posicaoInicio],rtDestinoF[posicaoInicio])!=0);
	v.valPassagem = PrecoPassagem(rtOrigemF[posicaoInicio], rtDestinoF[posicaoInicio]);
	InterfaceVenda4(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);

}

void Etapa4(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	char cod[10];
	cor(3);
	printf("\t\t\t -------------------------\n");
	printf("\t\t\t|       PASSAGEIROS       |\n");
	printf("\t\t\t -------------------------\n\n");
	cor(1);
	PrintarPassageirosArquivo();
	printf("\n");
	do
	{
		fflush(stdin);
		printf("Escolha o código do passageiro: ");
		scanf("%d", &v.codPassageiro);
		snprintf (cod, 10, "%d", v.codPassageiro);
		if(VerificarCodPassageiro(cod)!=1){
			printf("O número digitado não corresponde a nenhum passageiro!\n");
		}
	} while (VerificarCodPassageiro(cod)!=1);

	InterfaceVenda5(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
}

void Etapa5(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	system("cls");
	char matricula[10];
	int op=0;
	cor(3);
	printf("\t\t\t --------------------------------\n");
	printf("\t\t\t|       FORMA DE PAGAMENTO       |\n");
	printf("\t\t\t --------------------------------\n\n");
	cor(1);
	printf("Valor da passagem: ");
	cor(2);
	printf("R$%.2f\n\n", v.valPassagem);
	cor(1);
	do{
		fflush(stdin);
		cor(3);printf("[1] ");cor(1);
		printf("Dinheiro\n");
		cor(3);printf("[2] ");cor(1);
		printf("Cartão de crédito\n");
		cor(3);printf("[3] ");cor(1);
		printf("Cartão de débito\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1 && op!=2 && op!=3);

	if (op==1)
	{
		fflush(stdin);
		printf("Digite a matrícula do funcionário: ");
		scanf("%[^\n]", matricula);
		if(VerificarMatFuncionario(matricula)==0){
			printf("\nA matrícula não pertence a nenhum funcionário!\n");
			do
			{
				fflush(stdin);
				cor(3);printf("[1] ");cor(1);
				printf("Voltar\n");
				printf("Escolha: ");
				scanf("%d", &op);
			} while (op!=1);

			InterfaceVenda5(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		}else{
			v.tipoPagamento = 1;
		}
	}
	else{
		v.tipoPagamento = op;
	}

	for(int i=rtOrigemF[posicaoInicio]; i<=rtDestinoF[posicaoInicio]; i++){
		TornarCadeiraIndisponivel(i, v.poltrona);
	}
	InterfaceVenda6(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
}

float PrecoPassagem(int iniRT, int fimRT){
	float DIST=0, MILHA=0, PER=0, DUFFS=0, RET=0, PROC=0, preco=0;
	int tipoDia, retorno;

	struct tm *dataAtual;
	time_t segundos;
	time(&segundos);
	dataAtual = localtime(&segundos);

	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));
	RotaTrecho rt;
	int a=0;
	FILE *arq = AbrirArquivo("RotaTrecho.dat","rb");
	while(fread(&rt, sizeof(rt),1, arq)==1){
		rt1[a] = rt;
		rt1 = realloc(rt1,(a+2)*sizeof(RotaTrecho));
		a++;
	}
	fclose(arq);

	FILE *arq1 = AbrirArquivo("Trecho.dat","rb");
	Trecho *t1;
	t1 = malloc(sizeof(Trecho));

	int cont=0;
	Trecho t;
	while(fread(&t, sizeof(t),1, arq1)==1){
		t1[cont] = t;
		t1 = realloc(t1,(cont+2)*sizeof(Trecho));
		cont++;
	}
	fclose(arq1);


	Rota *r1 = malloc(sizeof(Rota));
	Rota r;
	int b=0;
	FILE *arq2 = AbrirArquivo("Rota.dat","rb");
	while(fread(&r, sizeof(r),1, arq2)==1){
		r1[b] = r;
		r1 = realloc(r1,(b+2)*sizeof(Rota));
		b++;
	}
	fclose(arq2);

	for(int i=0; i<b; i++){
		if(r1[i].codRota==rt1[iniRT].codRota){
			tipoDia = r1[i].tipoDia;
			retorno = r1[i].retorno;
		}
	}

	float milhas=0;
	Data dtInicio, dtFim;

	for(int i=iniRT; i<=fimRT; ++i){
		BuscarInformacoesTrecho(rt1[i].codTrecho, &dtInicio, &dtFim, &milhas);
		DIST += milhas;
	}

	int numPoltronas;
	for(int i=iniRT; i<=fimRT; ++i){
		if(r1[i].codRota==rt1[iniRT].codRota)
			numPoltronas = r1[i].numPoltrona;
	}

    //verifica a distancia entre a origem e o destino para o calculo do fator DIST
	if(DIST<=500.0)
		MILHA = 0.36;
	else if(DIST>500 && DIST<=800)
		MILHA = 0.29;
	else
		MILHA = 0.21;

    //verifica o tipo de dia na rota
	if(tipoDia==1)
		DUFFS = 1;
	else if(tipoDia==2)
		DUFFS = 5.56;
	else if(tipoDia==3)
		DUFFS = 1.21;

    //verifica o periodo de retorno para o calculo do fator RET
	if(retorno<=2)
		RET = 1.09;
	else if(retorno>2 && retorno<=5)
		RET = 1.05;
	else if(retorno>5 && retorno<=8)
		RET = 1.02;
	else
		RET = 1;

    //compara data
	int dataViagemDias = (rt1[iniRT].dtInicio.ano*360)+(rt1[iniRT].dtInicio.mes*30)+rt1[iniRT].dtInicio.dia;
	int dataAtualDias = ((dataAtual->tm_year+1900)*360)+((dataAtual->tm_mon+1)*30)+dataAtual->tm_mday;
	int difDias = dataViagemDias-dataAtualDias;

	if(difDias>0 && difDias<=3)
		PER = 4.52;
	else if(difDias>3 && difDias<=6)
		PER = 3.21;
	else if(difDias>6 && difDias<=10)
		PER = 2.25;
	else if(difDias>10 && difDias<=15)
		PER = 1.98;
	else if(difDias>15 && difDias<=20)
		PER = 1.78;
	else if(difDias>20 && difDias<=30)
		PER = 1.65;
	else
		PER = 1.45;

	int poltronasVagas;
	for(int i=1; i<=numPoltronas; ++i){
		if(PoltronaOcupadaIntervaloTrechos(i, iniRT, fimRT)==0)
			poltronasVagas++;
	}

	float porcPoltronasVagas = (poltronasVagas/numPoltronas)*100.0;

	if(porcPoltronasVagas<10)
		PROC = 1.35;
	else if(porcPoltronasVagas>=10 && porcPoltronasVagas<20)
		PROC = 1.2;
	else if(porcPoltronasVagas>=20 && porcPoltronasVagas<40)
		PROC = 1.15;
	else if(porcPoltronasVagas>=40 && porcPoltronasVagas<60)
		PROC = 1;
	else if(porcPoltronasVagas>=60 && porcPoltronasVagas<70)
		PROC = 0.95;
	else if(porcPoltronasVagas>=70 && porcPoltronasVagas<=90)
		PROC = 0.85;
	else if(porcPoltronasVagas>90)
		PROC = 0.75;

	preco = DIST*MILHA*PER*DUFFS*RET*PROC;
	return preco;
}

void OrigemTrechoPorCodigo(Trecho trechos[], int numTrechos, int codigoTrecho, char *origem){
	for(int i=0; i<numTrechos; i++){
		if(codigoTrecho==trechos[i].codTrecho)
			strcpy(origem, trechos[i].origem);
	}
}

void DestinoTrechoPorCodigo(Trecho trechos[], int numTrechos, int codigoTrecho, char *destino){
	for(int i=0; i<numTrechos; i++){
		if(codigoTrecho==trechos[i].codTrecho)
			strcpy(destino, trechos[i].destino);
	}
}

void CriarVetorRotasOrigemDestino(char origem[], char destino[], int *posiOrigem, int *posiDestino, int *encontradas){
	Trecho t;
	Rota r;
	RotaTrecho rt;
	Trecho *t1 = malloc(sizeof(Trecho));
	Rota *r1 = malloc(sizeof(Rota));
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));
	int a=0, indicePonteiros=0, b=0, c=0;
	int posicaoOrigem=-1, posicaoDestino=-1, numPoltrona=1, codRotaAtual=-1;
	char origemAtual[100], destinoAtual[100];
	*encontradas = 0;

	FILE *arq1 = AbrirArquivo("Rota.dat","rb");
	while(fread(&r, sizeof(r),1, arq1)==1){
		r1[a] = r;
		r1 = realloc(r1,(a+2)*sizeof(Rota));
		a++;
	}
	fclose(arq1);

	FILE *arq2 = AbrirArquivo("RotaTrecho.dat","rb");
	while(fread(&rt, sizeof(rt),1, arq2)==1){
		rt1[b] = rt;
		rt1 = realloc(rt1,(b+2)*sizeof(RotaTrecho));
		b++;
	}
	fclose(arq2);

	FILE *arq3 = AbrirArquivo("Trecho.dat","rb");
	while(fread(&t, sizeof(t),1, arq3)==1){
		t1[c] = t;
		t1 = realloc(t1,(c+2)*sizeof(Trecho));
		c++;
	}
	fclose(arq3);

	for(int i=0; i<b; i++){

		OrigemTrechoPorCodigo(t1, c, rt1[i].codTrecho, origemAtual);
		DestinoTrechoPorCodigo(t1, c, rt1[i].codTrecho, destinoAtual);

		if(i==0){
			codRotaAtual = rt1[i].codRota;
		}
		if(rt1[i].codRota==codRotaAtual){
			if(strcmp(origem, origemAtual)==0){
				posicaoOrigem = i;
			}

			if(strcmp(destino, destinoAtual)==0){
				posicaoDestino = i;
			}
		}else{
			codRotaAtual = rt1[i].codRota;

			if(posicaoDestino==-1 || posicaoOrigem==-1){
				posicaoDestino = -1;
				posicaoOrigem = -1;
			}

			i--;
		}
		if(posicaoDestino!=-1 && posicaoOrigem!=-1){
			posiOrigem[indicePonteiros] = posicaoOrigem;
			posiDestino[indicePonteiros] = posicaoDestino;
			indicePonteiros = indicePonteiros+1;
			*encontradas = *encontradas+1;
			posicaoDestino = -1;
			posicaoOrigem = -1;
		}
	}
}

void FiltrarRotasDisponiveis(int *origem, int *destino,int *origemFiltrado,int *destinoFiltrado,  int tamVetor, int *tamVetFiltrado){ //minha
	int disponivel =0, numCadeiras=0, contRota, contRotaTrecho;
	FILE *arq;
	Rota r;
	RotaTrecho rt;
	Rota *r1 = malloc(sizeof(Rota));
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));

	*tamVetFiltrado=0;
	arq = AbrirArquivo("Rota.dat","rb");
	int i=0;

	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	contRota = i;
	fclose(arq);

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;

	while(fread(&rt, sizeof(rt),1, arq)==1){
		rt1[i] = rt;
		rt1 = realloc(rt1,(i+2)*sizeof(RotaTrecho));
		i++;
	}
	contRotaTrecho = i;
	fclose(arq);
	disponivel=0;

	for (int i =0;i<tamVetor ;i++){
		for (int j=0; j< contRota;j++){
			if(r1[j].codRota==rt1[origem[i]].codRota){
				numCadeiras=r1[j].numPoltrona;
			}
		}
		for ( int j=1; j<=numCadeiras;j++){
			if(PoltronaOcupadaIntervaloTrechos(j,origem[i],destino[i])==0 && origem[i]<=destino[i]){
				disponivel = 1;
			}
		}
		if (disponivel==1)
		{
			origemFiltrado[*tamVetFiltrado] = origem[i];
			destinoFiltrado[*tamVetFiltrado] = destino[i];
			*tamVetFiltrado = *tamVetFiltrado + 1;
		}
	}
}

void TornarCadeiraDisponivel() {
	FILE *arq;
	Poltrona polt;
	Poltrona *polt1 = malloc(sizeof(Trecho));

	arq = AbrirArquivo("Poltrona.dat","rb");
	int i=0;

	while(fread(&polt, sizeof(polt),1, arq)==1){
		polt1[i] = polt;
		polt1 = realloc(polt1,(i+2)*sizeof(Poltrona));
		i++;
	}
	int contPoltrona = i;
	fclose(arq);

	for (int i=0;i<contPoltrona ;i++){
		polt1[i].ocupada = 0;
	}

	arq = fopen("Poltrona.dat","wb");
	InserirPoltronaNoArquivo(polt1, arq, contPoltrona);
	fclose(arq);
}

void TornarCadeiraIndisponivel(int posRotaTrecho, int numCadeira) {
	FILE *arq;
	RotaTrecho rt;
	Poltrona polt;
	Poltrona *polt1 = malloc(sizeof(Poltrona));
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));
	int i=0;

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	while(fread(&rt, sizeof(rt),1, arq)==1){
		rt1[i] = rt;
		rt1 = realloc(rt1,(i+2)*sizeof(RotaTrecho));
		i++;
	}
	int contTrecho = i;
	fclose(arq);

	i=0;
	arq = AbrirArquivo("Poltrona.dat","rb");
	while(fread(&polt, sizeof(polt),1, arq)==1){
		polt1[i] = polt;
		polt1 = realloc(polt1,(i+2)*sizeof(Poltrona));
		i++;
	}
	int contPoltrona = i;
	fclose(arq);

	for (int i=0;i<contPoltrona ;i++){
		if(polt1[i].PosRotaTrecho == posRotaTrecho && polt1[i].numPoltrona == numCadeira){
			polt1[i].ocupada = 1;
		}
	}
	arq = fopen("Poltrona.dat","wb");
	InserirPoltronaNoArquivo(polt1, arq, contPoltrona);
	fclose(arq);
	fflush(stdin);
}

int PoltronaOcupadaIntervaloTrechos(int num, int origem, int destino) { //ok
	int ocupada=0, contPoltrona;
	FILE *arq;
	Rota r;
	Poltrona polt;
	RotaTrecho rt;
	Rota *r1 = malloc(sizeof(Trecho));
	Poltrona *polt1 = malloc(sizeof(Trecho));
	RotaTrecho *rt1 = malloc(sizeof(RotaTrecho));

	arq = AbrirArquivo("Rota.dat","rb");
	int i=0;

	while(fread(&r, sizeof(r),1, arq)==1){
		r1[i] = r;
		r1 = realloc(r1,(i+2)*sizeof(Rota));
		i++;
	}
	fclose(arq);

	arq = AbrirArquivo("RotaTrecho.dat","rb");
	i=0;

	while(fread(&rt, sizeof(rt),1, arq)==1){
		rt1[i] = rt;
		rt1 = realloc(rt1,(i+2)*sizeof(RotaTrecho));
		i++;
	}
	int contTrecho = i;
	fclose(arq);

	i=0;
	arq = AbrirArquivo("Poltrona.dat","rb");
	while(fread(&polt, sizeof(polt),1, arq)==1){
		polt1[i] = polt;
		polt1 = realloc(polt1,(i+2)*sizeof(Poltrona));
		i++;
	}
	contPoltrona = i;
	fclose(arq);
	if (r1[origem].numPoltrona<num || num<=0)
	{
		ocupada = 1;
	}else{
		for (int i=0;i<contPoltrona ;i++){
			if(polt1[i].PosRotaTrecho >= origem && polt1[i].PosRotaTrecho <= destino && polt1[i].numPoltrona == num){
				if(polt1[i].ocupada==1){
					ocupada =1;
				}
			}
		}
	}
	return ocupada;
}
void center_print(const char *s, int width)
{
	int length = strlen(s);
	int i;
	for (i=0; i<=(width-length)/2; i++) {
		fputs(" ", stdout);
	}
	fputs(s, stdout);
	i += length;
	for (; i<=width; i++) {
		fputs(" ", stdout);
	}
}
void TicketTxt(Venda v){
	PassageiroFidelizado p, pAtual;
	int cont=0, op, posicao=0;
	FILE *arq = AbrirArquivo("Passageiro.dat","rb");
	char nomeArquivo[100], comecoNomeArquivo[30] = "Tickets/Ticket-", fimNomeArquivo[30] = ".txt", cod[10];
	char formaPag[30];
	while(fread(&p, sizeof(p),1, arq)==1){
		snprintf (cod, 10, "%d", v.codPassageiro);
		if(strcmp(cod, p.codPassageiro)==0){
			pAtual = p;
		}
	}

	do
	{
		srand(time(NULL));
		v.codigo = rand()%100000;
	} while (VerificarCodVenda(v.codigo)==1);

	snprintf (nomeArquivo, 100, "%s%d", comecoNomeArquivo, v.codigo );

	strcat(nomeArquivo,fimNomeArquivo);

	if(v.tipoPagamento == 1)
		strcpy(formaPag,"Dinheiro");
	else if(v.tipoPagamento == 2)
		strcpy(formaPag, "Cartão de crédito");
	else if(v.tipoPagamento == 3)
		strcpy(formaPag, "Cartão de débito");

	cor(3);
	printf("\t\t\t --------------\n");
	printf("\t\t\t|    TICKET    |\n");
	printf("\t\t\t --------------\n\n");
	cor(1);

	printf("Codigo da viagem: %d\n", v.codigo);
	printf("Codigo do passageiro: %d\n", v.codPassageiro);
	printf("Nome do passageiro: %s\n", pAtual.nome);
	printf("RG do passageiro: %s\n", pAtual.RG);
	printf("CPF do passageiro: %s\n", pAtual.CPF);
	printf("Poltrona: %d\n", v.poltrona);
	printf("Origem: %s\n", v.origem);
	printf("Destino: %s\n", v.destino);
	printf("Hora de embarque: %.2d:%.2d\n", v.hrEmbarque.hora, v.hrEmbarque.min);
	printf("Hora de desembarque: %.2d:%.2d\n", v.hrDesembarque.hora, v.hrDesembarque.min);
	printf("Data de embarque: %.2d/%.2d/%.4d\n", v.dtEmbarque.dia, v.dtEmbarque.mes, v.dtEmbarque.ano);
	printf("Data de desembarque: %.2d/%.2d/%.4d\n", v.dtDesembarque.dia, v.dtDesembarque.mes, v.dtDesembarque.ano);
	printf("Valor da passagem: R$%.2f\n", v.valPassagem);
	printf("Forma de pagamento: %s\n\n", formaPag);

	arq = AbrirArquivo(nomeArquivo,"w+");
	fprintf(arq ,"Codigo da viagem: %d\n", v.codigo);
	fprintf(arq ,"Codigo do passageiro: %d\n", v.codPassageiro);
	fprintf(arq ,"Nome do passageiro: %s\n", pAtual.nome);
	fprintf(arq ,"RG do passageiro: %s\n", pAtual.RG);
	fprintf(arq ,"CPF do passageiro: %s\n", pAtual.CPF);
	fprintf(arq ,"Poltrona: %d\n", v.poltrona);
	fprintf(arq ,"Origem: %s\n", v.origem);
	fprintf(arq ,"Destino: %s\n", v.destino);
	fprintf(arq ,"Hora de embarque: %.2d:%.2d\n", v.hrEmbarque.hora, v.hrEmbarque.min);
	fprintf(arq ,"Hora de desembarque: %.2d:%.2d\n", v.hrDesembarque.hora, v.hrDesembarque.min);
	fprintf(arq ,"Data de embarque: %.2d/%.2d/%.4d\n", v.dtEmbarque.dia, v.dtEmbarque.mes, v.dtEmbarque.ano);
	fprintf(arq ,"Data de desembarque: %.2d/%.2d/%.4d\n", v.dtDesembarque.dia, v.dtDesembarque.mes, v.dtDesembarque.ano);
	fprintf(arq ,"Valor da passagem: R$%.2f\n", v.valPassagem);
	fprintf(arq ,"Forma de pagamento: %s\n", formaPag);
	fclose(arq);

	FILE *arqVenda = fopen("Venda.dat","ab");
	InserirVendaNoArquivo(v, arqVenda);
	fclose(arqVenda);

	do{
		fflush(stdin);
		cor(3);printf("[1] ");cor(1);
		printf("Voltar\n");
		printf("Escolha: ");
		scanf("%d", &op);
	} while (op!=1);
	InterfaceMenu1();
}

#endif
