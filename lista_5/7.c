#include <stdio.h>
#include <stdlib.h>

float Media(int *vet, int tamVet){
    float somaVet = 0, media;
    for(int i =0; i<tamVet; i++){
        somaVet+=vet[i];
    }

    media = somaVet/tamVet;
    return media;
}

void PrintaVetor(int *vet, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
}

int main(){
    int tam, deslocador=0;
    char resp;
    int *vet;
    float media;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = malloc(tam*sizeof(int));

    for(int i=0; i<tam; i++){
        fflush(stdin);
        printf("Digite o valor %d do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }

    do{
        fflush(stdin);
        printf("Deseja adicionar mais posições?(S/N)");
        scanf("%c", &resp);
        if(resp=='S'){
            fflush(stdin);
            printf("Deseja adicionar mais quantos?");
            scanf("%d", &deslocador);
            vet = realloc(vet, (tam+deslocador)*sizeof(int));
            for(int i=tam; i<tam+deslocador; i++){
                fflush(stdin);
                printf("Digite o valor %d do vetor: ", i+1);
                scanf("%d", &vet[i]);
            }
            tam += deslocador;
        }
    }while(resp=='S');

    media = Media(vet, tam);
    printf("\nVetor: \n");
    PrintaVetor(vet, tam);
    printf("\nMedia: %.2f\n", media);

    free(vet);

}
