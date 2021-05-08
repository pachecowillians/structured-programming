#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
    int h1,m1,s1,h2,m2,s2,t1,t2,tot;
    printf("Digite o tempo inicial (h,m,s): ");
    scanf("%d %d %d", &h1, &m1, &s1);
    printf("Digite o tempo final (h,m,s): ");
    scanf("%d %d %d", &h2, &m2, &s2);

    t1 = h1*3600 + m1*60 + s1; 
    t2 = h2*3600 + m2*60 + s2; 
    
    if (t1>t2)
        tot = t1-t2;
    else
        tot = t2-t1;
        
    printf("\nHoras: %d", tot/3600);
    printf("\nMinutos: %d", (tot%3600)/60);
    printf("\nSegundos: %d\n", (tot%3600)%60);
    return 0;
}