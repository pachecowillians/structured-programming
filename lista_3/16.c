#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int a[10], b[10], c[20], i=0, cOrdenado[20], j=0, posicao=0, menor=0, x;
    
    for(i=0; i<10; i++){
        printf("Digite o %d valor de A: ", i+1);
        scanf("%d", &a[i]);
    }
    for(i=0; i<10; i++){
        printf("Digite o %d valor de B: ", i+1);
        scanf("%d", &b[i]);
    }
    for(i=0; i<20; i++){
        if(i<10)
            c[i] = a[i];
        else
            c[i] = b[i-10];
    }

    for (j = 1; j < 20; ++j) {
        x = c[j];
        for (i = j-1; i >= 0 && c[i] > x; --i)
         c[i+1] = c[i];
     c[i+1] = x;
 }

 for(i=0; i<20; i++){
     printf("%d\n", c[i]);
 }
 
 
 return 0;
}
