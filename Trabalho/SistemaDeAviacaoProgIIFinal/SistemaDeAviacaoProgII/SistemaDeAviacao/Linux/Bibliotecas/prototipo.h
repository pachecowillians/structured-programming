// ---------------------------------- PROTÓTIPOS -------------------------------------------
// Definição dos protótipos das funções com intuito de reduzir os warnings e garantir mais qualidade ao sistema.

#ifndef PROTOTIPO_H
#define PROTOTIPO_H

FILE * AbrirArquivo(char *nome, char *op);
int VerificarCodPassageiro(char cod[30]);
float PrecoPassagem(int iniRT, int fimRT);
int VerificarCodAeroporto(char cod[30]);
int VerificarMatFuncionario(char cod[30]);
int VerificarCodTrecho(int cod);
int VerificarCodRota(int cod);
int VerificarCodVenda(int cod);
void InserirPassageirosNoArquivo(PassageiroFidelizado *p, FILE *arq, int num);
void InserirAeroportoNoArquivo(Aeroporto *p, FILE *arq, int num);
void InserirFuncionariosNoArquivo(Funcionario *p, FILE *arq, int num);
void InserirTrechosNoArquivo(Trecho *p, FILE *arq, int num);
void InserirRotasNoArquivo(Rota *p, FILE *arq, int num);
void InserirRotasTrechosNoArquivo(RotaTrecho *p, FILE *arq, int num);
void InserirVendaNoArquivoTxt(char p[100], FILE *arq);
void InserirVendaNoArquivo(Venda p, FILE *arq);
void InserirPoltronaNoArquivo(Poltrona *p, FILE *arq, int num);
void CadastrarTrechos();
void CadastrarRotas();
void CadastrarFuncionarios();
void CadastrarAeroportos();
void CadastrarPassageiros();
void ListarRotasArquivo();
void ListarCidadeArquivo(int opcao);
void ListarPassageirosArquivo();
void ListarTrechosArquivo();
void ListarFuncionariosArquivo();
void ListarAeroportosArquivo();
void ListarHorarios(int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado);
void PrintarCidadeArquivo(int opcao, char nome[50]);
void PrintarPassageirosArquivo();
void PrintarTrechosArquivo(int cod);
void PrintarCadeirasDisponiveis(int origem, int destino);
int BuscaVetorCidades(int *vetCidades, int tam, int val);
void PesquisarPassageiros();
void PesquisarFuncionarios();
void TornarCadeiraDisponivel();
void TornarCadeiraIndisponivel(int posRotaTrecho, int numCadeira);
int PoltronaOcupadaIntervaloTrechos(int num, int origem, int destino);
void InterfaceMenu1();
void InterfaceMenu2();
void InterfaceVenda1();
void InterfaceVenda2(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado);
void InterfaceVenda3(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void InterfaceVenda4(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void InterfaceVenda5(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void InterfaceVenda6(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void Etapa1();
void Etapa2(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado);
void Etapa3(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void Etapa4(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void Etapa5(Venda v, int *rtOrigemF, int *rtDestinoF, int tamVetFiltrado, int posicaoInicio);
void DestinoTrechoPorCodigo(Trecho trechos[], int numTrechos, int codigoTrecho, char *destino);
void OrigemTrechoPorCodigo(Trecho trechos[], int numTrechos, int codigoTrecho, char *origem);
void CriarVetorRotasOrigemDestino(char origem[], char destino[], int *posiOrigem, int *posiDestino, int *encontradas);
void FiltrarRotasDisponiveis(int *origem, int *destino,int *origemFiltrado,int *destinoFiltrado,  int tamVetor, int *tamVetFiltrado);
int ExisteOrigem(char *origem);
int ExisteDestino(char *destino);
void TicketTxt(Venda v);
void BuscarInformacoesTrecho(int codTrecho, Data *dtInicio, Data *dtFim, float *milhas);
int main();

#endif
