// ---------------------------------- STRUCTS -------------------------------------------
// Structs usadas no sistema

#ifndef STRUCT_H
#define STRUCT_H

typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	int hora, min;
}Hora;

typedef struct{
	int bagagemExtra ;
	char codPassageiro[50], RG[30],nome[50], CPF[50],telefone[50], email[50], contatoEmergencia[50] ;
	Data dtNascimento;
}PassageiroFidelizado;

typedef struct{
	char codAeroporto[50];
	char nomeAeroporto[50];
	char cidade[50];
	char estado[50];
}Aeroporto;

typedef struct{
	int codRota;
	int numPoltrona, numTrechos;
	Hora hrInicio, hrFim;
	Data dtInicio, dtFim;
	char origem[50], destino[50];
	float milhas;
	int tipoDia;
	int retorno;
}Rota;

typedef struct{
	int codTrecho;
	char aeroportoOrigem[50], aeroportoDestino[50];
	float milhas;
	char origem[50], destino[50];
}Trecho;

typedef struct{
	int codRota,codTrecho;
	Hora hrInicio, hrFim;
	Data dtInicio, dtFim;
	int diario;
}RotaTrecho;

typedef struct{
	int PosRotaTrecho;
	int numPoltrona;
	int ocupada;
}Poltrona;

typedef struct{
	char matricula[50], nome[50], cargo[50];
}Funcionario;

typedef struct{
	int codigo, codPassageiro, poltrona, tipoPagamento;
	char origem[50], destino[50];
	Hora hrEmbarque, hrDesembarque;
	Data dtEmbarque, dtDesembarque;
	float valPassagem, troco, milhas;
}Venda;
#endif
