#include <stdio.h>
#include <stdlib.h>

void func(float *vet, int tamVet, float *maior, float *menor, float *media){
    float max = vet[0];
    float min = vet[0];
    float somaVet = 0;
    for(int i =0; i<tamVet; i++){
        if(max<vet[i])
            max = vet[i];
        if(min>vet[i])
            min = vet[i];
        somaVet+=vet[i];
    }
    *maior = max;
    *menor = min;
    *media = somaVet/tamVet;
}

int main(){
    int tam;
    float *vet, maior, menor, media;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = malloc(tam*sizeof(float));

    for(int i=0; i<tam; i++){
        fflush(stdin);
        printf("Digite o valor %d do vetor: ", i+1);
        scanf("%f", &vet[i]);
    }
    func(vet, tam,&maior, &menor, &media);

    printf("\nMaior: %.2f", maior);
    printf("\nMenor: %.2f", menor);
    printf("\nMedia: %.2f\n", media);

    free(vet);

}
