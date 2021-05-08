// ---------------------------------- FUNC. VERIFICACAO -------------------------------------------
// Funções de verificação e tratamento de erros do sistema

#ifndef VERIFICACAO_H
#define VERIFICACAO_H

int VerificarCodPassageiro(char cod[30]){
	PassageiroFidelizado p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Passageiro.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (strcmp(cod,p.codPassageiro)==0)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int VerificarCodAeroporto(char cod[30]){
	Aeroporto p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Aeroporto.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (strcmp(cod,p.codAeroporto)==0)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int VerificarMatFuncionario(char cod[30]){
	Funcionario p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Funcionario.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (strcmp(cod,p.matricula)==0)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int VerificarCodTrecho(int cod){
	Trecho p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Trecho.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (cod == p.codTrecho)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int VerificarCodRota(int cod){
	Rota p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Rota.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (cod==p.codRota)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int VerificarCodVenda(int cod){
	Venda p;
	int cont=0, op, existe = 0;
	FILE *arq = AbrirArquivo("Venda.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if (cod==p.codigo)
			existe = 1;
	}

	fclose(arq);
	return existe;
}

int ExisteOrigem(char *origem){
	Trecho p;
	int cont=0, existe=0;
	FILE *arq = AbrirArquivo("Trecho.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if(strcmp(origem, p.origem)==0)
		{
			existe = 1;
		}
	}
	return existe;
}

int ExisteDestino(char *destino){
	Trecho p;
	int cont=0, existe=0;
	FILE *arq = AbrirArquivo("Trecho.dat","rb");

	while(fread(&p, sizeof(p),1, arq)==1){
		if(strcmp(destino, p.destino)==0)
		{
			existe = 1;
		}
	}
	return existe;
}

#endif
