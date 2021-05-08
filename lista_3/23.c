#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int n1,n2, soma=0;
    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    
    for(int i=0; i<n2; i++){
        soma+=n1;
    }
    
    printf("Resultado: %d\n", soma);
    
    return 0;
}
