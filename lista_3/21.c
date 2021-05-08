#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

float a[30];

void pesquisar(float vet[30], int elem){
    int retorno=-1;
    for(int i=0; i<30; i++){
        if(vet[i]==elem){
            retorno = i;
        }
    }
    if(retorno==-1)
        printf("\nO valor não existe no vetor");
    else
        printf("\nO valor existe na posição: %d", retorno);
    printf("\n");
}

void ordenarCrescente(){
    int aux=0;
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            if (a[i] < a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    for (int i = 0; i < 30; i++){
        printf("%.0f ", a[i]);
    }
    printf("\n");
}

void ordenarDecrescente(){
    int aux=0;
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 30; j++){
            if (a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    for (int i = 0; i < 30; i++){
        printf("%.0f ", a[i]);
    }
    printf("\n");
}

int main()
{
    int i=0, op=0;
    float elemento=0;
    do{
        
        printf("\n1 - Ler valores no vetor");
        printf("\n2 - Pesquisar elementos no vetor");
        printf("\n3 - Ordenar o vetor de forma crescente");
        printf("\n4 - Ordenar o vetor de forma decrescente");
        printf("\n5 - Sair");
        printf("\nDigite a opção: ");
        scanf("%d", &op);
        switch(op){
            case 1: 
                for(i=0; i<30; i++){
                    printf("Digite o %d valor: ", i+1);
                    scanf("%f", &a[i]);
                }
                break;
            case 2:
                printf("Digite o elemento que deseja pesquisar: ");
                scanf("%f", &elemento);        
                pesquisar(a, elemento);
                break;
            case 3:
                ordenarCrescente();
                break;
            case 4:
                ordenarDecrescente();
                break;
            case 5:
                exit(1);
            
        }
    }while(op!=5);
    
    return 0;
}
