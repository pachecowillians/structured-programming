#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int num;
    printf("Deseja inserir quantos números? ");
    scanf("%d", &num);
    
    int a[num];
    
    for(int i=0; i<num; i++){
        printf("Digite o número: ");
        scanf("%d", &a[i]);
    }
    printf("\n");
    for(int i=num-1; i>=0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
