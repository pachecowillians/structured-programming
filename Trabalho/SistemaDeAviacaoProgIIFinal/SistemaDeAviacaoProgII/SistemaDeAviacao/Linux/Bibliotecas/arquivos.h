// ---------------------------------- FUNC. ARQUIVOS -------------------------------------------
// Funções de interação com arquivos

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

FILE * AbrirArquivo(char *nome, char *op){
	FILE *arq = fopen(nome,op);
	FILE *arq_criado;
	if (arq == NULL){
        arq_criado = AbrirArquivo(nome, "wb");  //se o arquivo não existir, cria um novo
        return arq_criado;
    }
    return arq;
}

void InserirPassageirosNoArquivo(PassageiroFidelizado *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirAeroportoNoArquivo(Aeroporto *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirFuncionariosNoArquivo(Funcionario *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirTrechosNoArquivo(Trecho *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirRotasNoArquivo(Rota *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirRotasTrechosNoArquivo(RotaTrecho *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

void InserirVendaNoArquivoTxt(char *p, FILE *arq){
	fwrite(&p,sizeof(p),1,arq);
}

void InserirVendaNoArquivo(Venda p, FILE *arq){
	fwrite(&p,sizeof(p),1,arq);
}

void InserirPoltronaNoArquivo(Poltrona *p, FILE *arq, int num){
	for (int i = 0; i < num; ++i){
		fwrite(&p[i],sizeof(p[i]),1,arq);
	}
}

#endif
