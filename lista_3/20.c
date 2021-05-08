#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int i=0;
    float a[20], maior=0, menor=0, soma=0, xi2=0;
    __fpurge(stdin);
    for(i=0; i<20; i++){
        printf("Digite o desempenho do %d colocado: ", i+1);
        scanf("%f", &a[i]);
    }

    for(i=0; i<20; i++){
        if (i==0){
            maior = a[i];
            menor = a[i];
        }
        if(a[i]>maior)
            maior = a[i];
        if(a[i]<menor)
            menor = a[i];
        soma+=a[i];
    }
    //pela fórmula da variância, é o somatório do (valor-média)²/n-1. Aplicando a fórmula:
    //Considerei o xi como sendo a média e calculei a seguir (valor-media)²
    for (int i = 0; i < 20; ++i)
    {
        xi2 += pow((a[i]-(soma/20)),2);
    }
    printf("\nMaior nota: %.0f", maior);
    printf("\nMenor nota: %.0f", menor);
    printf("\nMédia das notas: %.2f", soma/20);
    printf("\nVariância das notas: %.2f\n", xi2/(20-1));

    return 0;
}
