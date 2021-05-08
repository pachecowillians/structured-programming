#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ano;
    char modelo[30], marca[30], cor[30], placa[30];
    float valor;
}Carro;

void PreencherCarro(Carro *c){
    fflush(stdin);
    printf("Digite o ano do carro: ");
    scanf("%d", &c->ano);
    fflush(stdin);
    printf("Digite o modelo do carro: ");
    scanf("%[^\n]", c->modelo);
    fflush(stdin);
    printf("Digite a marca do carro: ");
    scanf("%[^\n]", c->marca);
    fflush(stdin);
    printf("Digite o cor do carro: ");
    scanf("%[^\n]", c->cor);
    fflush(stdin);
    printf("Digite o placa do carro: ");
    scanf("%[^\n]", c->placa);
    fflush(stdin);
    printf("Digite o valor do carro: ");
    scanf("%f", &c->valor);
}

void ImprimirCarro(Carro c){
    printf("\nAno: %d", c.ano);
    printf("\nModelo: %s", c.modelo);
    printf("\nMarca: %s", c.marca);
    printf("\nCor: %s", c.cor);
    printf("\nPlaca: %s", c.placa);
    printf("\nValor: %.2f", c.valor);
}

int main(){
    Carro *c, car;
    c = &car;
    PreencherCarro(c);
    ImprimirCarro(car);
    free(c);
}
