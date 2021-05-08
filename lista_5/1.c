#include <stdio.h>
#include <stdlib.h>

void OrdenaVetorCrescente(int *vet, int tam){
    int aux;
    for(int i=0; i<tam; i++){
        for(int j = 0; j<tam; j++){
            if(vet[i]<vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void OrdenaVetorDecrescente(int *vet, int tam){
    int aux;
    for(int i=0; i<tam; i++){
        for(int j = 0; j<tam; j++){
            if(vet[i]>vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void PrintaVetor(int *vet, int tam){
    int aux;
    for(int i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
}

int main(){
    int tam, *vet;;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = malloc(tam*sizeof(int));

    for(int i=0; i<tam; i++){
        fflush(stdin);
        printf("Digite o valor %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
    printf("\nCrescente: \n");
    OrdenaVetorCrescente(vet, tam);
    PrintaVetor(vet, tam);
    printf("\nDecrescente: \n");
    OrdenaVetorDecrescente(vet, tam);
    PrintaVetor(vet, tam);

}
