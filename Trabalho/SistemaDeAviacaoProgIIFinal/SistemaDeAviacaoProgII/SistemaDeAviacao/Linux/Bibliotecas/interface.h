// ---------------------------------------- FUNC. INTERFACE -----------------------------------
// Funções de interface

#ifndef INTERFACE_H
#define INTERFACE_H

void InterfaceVenda1(){
	system("clear");
	Rota p;
	PassageiroFidelizado pa;
	Funcionario f;
	int contRotas=0, contPassageiro=0, contFuncionario=0, op=0;

	FILE *arq = AbrirArquivo("Rota.dat","rb");

    //Não tem como ter rota sem ter trecho e aeroporto, então só testei se existem rotas cadastradas

	while(fread(&p, sizeof(p),1, arq)==1){
		contRotas++;
	}
	fclose(arq);

	arq = AbrirArquivo("Passageiro.dat","rb");

	while(fread(&pa, sizeof(pa),1, arq)==1){
		contPassageiro++;
	}
	fclose(arq);

	arq = AbrirArquivo("Funcionario.dat","rb");

	while(fread(&f, sizeof(f),1, arq)==1){
		contFuncionario++;
	}
	fclose(arq);

	if (contRotas == 0)
	{
		printf("Ainda não existem rotas cadastradas. Por favor, cadastre uma rota.\n");
		printf("\n");
		do
		{
			cor(3);
			printf("[1] " );
			cor(1);
			printf("Voltar\n" );
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu1();
	}else if (contPassageiro == 0)
	{
		printf("Ainda não existem passageiros cadastradas. Por favor, cadastre um passageiro.\n");
		printf("\n");
		do
		{
			printf("[1] Voltar\n" );
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu1();
	}else if (contFuncionario == 0)
	{
		printf("Ainda não existem funcionarios cadastradas. Por favor, cadastre um funcionarios.\n");
		printf("\n");
		do
		{
			cor(3);
			printf("[1] " );
			cor(1);
			printf("Voltar\n" );
			printf("Escolha: ");
			scanf("%d", &op);
		} while (op!=1);
		InterfaceMenu1();
	}else{
		system("clear");
		int opcao;

		cor(3);
		printf("\t\t\t --------------------\n");
		printf("\t\t\t|       VENDAS       |\n");
		printf("\t\t\t --------------------\n\n");
		cor(1);

		cor(3);
		printf("[1] ");
		cor(1);
		printf("Selecionar origem e destino\n");
		cor(3);
		printf("[2] ");
		cor(1);
		printf("Cadastrar rota\n");
		cor(3);
		printf("[3] ");
		cor(1);
		printf("Cadastrar trecho\n");
		cor(3);
		printf("[4] ");
		cor(1);
		printf("Voltar\n");

		printf("Escolha: ");
		scanf("%d",&opcao);
		system("clear");
		switch(opcao){
			case 1:
			Etapa1();
			break;
			case 2:
			CadastrarRotas();
			break;
			case 3:
			CadastrarTrechos();
			break;
			case 4:
			InterfaceMenu1();
			break;
			default:
			InterfaceVenda1();
			break;
		}
	}
}

void InterfaceVenda2(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado){
	system("clear");
	int opcao;
	cor(3);
	printf("\t\t\t --------------------\n");
	printf("\t\t\t|       VENDAS       |\n");
	printf("\t\t\t --------------------\n\n");
	cor(1);

	cor(3);
		printf("[1] ");
	cor(1);
	printf("Selecionar horários\n");
	cor(3);
		printf("[2] ");
	cor(1);
	printf("Voltar\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		Etapa2(v, rtOrigemF, rtDestinoF, tamVetFiltrado);
		break;
		case 2:
		InterfaceVenda1();
		break;
		default:
		InterfaceVenda2(v, rtOrigemF, rtDestinoF, tamVetFiltrado);
		break;
	}
}

void InterfaceVenda3(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	system("clear");
	int opcao;
	cor(3);
	printf("\t\t\t --------------------\n");
	printf("\t\t\t|       VENDAS       |\n");
	printf("\t\t\t --------------------\n\n");
	cor(1);

	cor(3);
		printf("[1] ");
	cor(1);
	printf("Selecionar Assentos\n");
	cor(3);
		printf("[2] ");
	cor(1);
	printf("Voltar\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		Etapa3(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
		case 2:
		InterfaceVenda2(v, rtOrigemF, rtDestinoF, tamVetFiltrado);
		break;
		default:
		InterfaceVenda3(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
	}
}

void InterfaceVenda4(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	system("clear");
	int opcao;

	cor(3);
	printf("\t\t\t --------------------\n");
	printf("\t\t\t|       VENDAS       |\n");
	printf("\t\t\t --------------------\n\n");
	cor(1);

	cor(3);
		printf("[1] ");
	cor(1);
	printf("Selecionar passageiro\n");
	cor(3);
		printf("[2] ");
	cor(1);
	printf("Cadastrar passageiro\n");
	cor(3);
		printf("[3] ");
	cor(1);
	printf("Voltar\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		Etapa4(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
		case 2:
		CadastrarPassageiros();
		break;
		case 3:
		InterfaceVenda3(v, rtOrigemF, rtDestinoF, tamVetFiltrado, 0);
		break;
		default:
		InterfaceVenda4(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
	}
}

void InterfaceVenda5(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	system("clear");
	int opcao;

	cor(3);
	printf("\t\t\t --------------------\n");
	printf("\t\t\t|       VENDAS       |\n");
	printf("\t\t\t --------------------\n\n");
	cor(1);

	cor(3);
		printf("[1] ");
	cor(1);
	printf("Selecionar a forma de pagamento\n");
	cor(3);
		printf("[2] ");
	cor(1);
	printf("Voltar\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		Etapa5(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
		case 2:
		InterfaceVenda4(v,0,0,0, posicaoInicio);
		break;
		default:
		InterfaceVenda5(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
	}
}

void InterfaceVenda6(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio){
	system("clear");
	int opcao;
	cor(3);
	printf("\t\t\t ----------------------\n");
	printf("\t\t\t|       E-TICKET       |\n");
	printf("\t\t\t ----------------------\n\n");
	printf("[1] ");
	cor(1);
	printf("Imprimir e-ticket\n");
	cor(3);
	printf("[2] ");
	cor(1);
	printf("Voltar\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		TicketTxt(v);
		break;
		case 2:
		InterfaceVenda5(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
		default:
		InterfaceVenda6(v, rtOrigemF, rtDestinoF, tamVetFiltrado, posicaoInicio);
		break;
	}
}

void InterfaceMenu1(){
	system("clear");
	int opcao;
	setlocale(LC_ALL, "Portuguese");

	cor(3);
	printf("\t\t\t ------------------\n");
	printf("\t\t\t|       MENU       |\n");
	printf("\t\t\t ------------------\n\n");
	cor(1);

	cor(3);
		printf("[1] ");
	cor(1);
	printf("Configurações\n");
	cor(3);
		printf("[2] ");
	cor(1);
	printf("Venda\n");
	cor(3);
		printf("[3] ");
	cor(1);
	printf("Sair\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
		system("clear");
		InterfaceMenu2();
		break;
		case 2:
		InterfaceVenda1();
		break;
		case 3:
            //sai do programa
		break;
		default:
		InterfaceMenu1();
		break;
	}
}

void InterfaceMenu2(){
	system("clear");
	setlocale(LC_ALL, "Portuguese");
	int opcao, op;

	cor(3);
	printf("\t\t\t ---------------------\n");
	printf("\t\t\t|    CONFIGURAÇÕES    |\n");
	printf("\t\t\t ---------------------\n\n");
	cor(1);

	cor(3);printf("[1]  ");cor(1);
	printf("Cadastrar aeroportos\n");
	cor(3);printf("[2]  ");cor(1);
	printf("Cadastrar trechos\n");
	cor(3);printf("[3]  ");cor(1);
	printf("Cadastrar rotas\n");
	cor(3);printf("[4]  ");cor(1);
	printf("Cadastrar passageiros fidelizados\n");
	cor(3);printf("[5]  ");cor(1);
	printf("Pesquisar/alterar dados de passageiros fidelizados\n");
	cor(3);printf("[6]  ");cor(1);
	printf("Cadastrar funcionários\n");
	cor(3);printf("[7]  ");cor(1);
	printf("Pesquisar/Alterar funcionários\n");
	cor(3);printf("[8]  ");cor(1);
	printf("Listar passageiros\n");
	cor(3);printf("[9]  ");cor(1);
	printf("Listar funcionarios\n");
	cor(3);printf("[10] ");cor(1);
	printf("Listar aeroportos\n");
	cor(3);printf("[11] ");cor(1);
	printf("Listar trechos\n");
	cor(3);printf("[12] ");cor(1);
	printf("Listar rotas\n");
	cor(3);printf("[13] ");cor(1);
	printf("Listar cidades\n");
	cor(3);printf("[14] ");cor(1);
	printf("Voltar\n");

	printf("Escolha: ");
	scanf("%d",&opcao);
	system("clear");
	switch(opcao){
		case 1:
		CadastrarAeroportos();
		break;
		case 2:
		CadastrarTrechos();
		break;
		case 3:
		CadastrarRotas();
		break;
		case 4:
		CadastrarPassageiros();
		break;
		case 5:
		PesquisarPassageiros();
		break;
		case 6:
		CadastrarFuncionarios();
		break;
		case 7:
		PesquisarFuncionarios();
		break;
		case 8:
		ListarPassageirosArquivo();
		break;
		case 9:
		ListarFuncionariosArquivo();
		break;
		case 10:
		ListarAeroportosArquivo();
		break;
		case 11:
		ListarTrechosArquivo();
		break;
		case 12:
		ListarRotasArquivo();
		break;
		case 13:
		system("clear");
		cor(3);
		printf("\t\t\t ---------------------\n");
		printf("\t\t\t|    CONFIGURAÇÕES    |\n");
		printf("\t\t\t ---------------------\n\n");
		cor(1);

		cor(3);printf("[1] ");cor(1);
		printf("Origem\n");
		cor(3);printf("[2] ");cor(1);
		printf("Destino\n");
		printf("Escolha: ");
		scanf("%d", &op);
		ListarCidadeArquivo(op);
		break;
		case 14:
		InterfaceMenu1();
		break;
		default:
		InterfaceMenu2();
		break;
	}
}

#endif
