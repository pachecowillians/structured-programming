#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int numQuestoes = 30;

struct aluno{
   int num;
   char prova[30][1];
   int acertos;
};

int main()
{
    
    char gabarito[numQuestoes][1];
    int n;
    __fpurge(stdin);
    printf("Digite o gabarito das 30 questões: ");
    for(int i=0; i<numQuestoes; i++){
        scanf("%s", gabarito[i]);
    }
    __fpurge(stdin);
    printf("Digite o número de alunos na turma: ");
    scanf("%d", &n);
    
    struct aluno a[n]; 
    
    for(int i=0; i<n; i++){   //alunos
        printf("Digite o número do aluno %d: ", i+1);
        scanf("%d", &a[i].num);
        printf("Digite o gabarito do aluno %d: ", i+1);
        a[i].acertos = 0;
        for(int j=0; j<numQuestoes; j++){ //questões
            scanf("%s", a[i].prova[j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<numQuestoes; j++){ //questões
            if((gabarito[j][0] == a[i].prova[j][0]))
                a[i].acertos++;
        }
    }
    
    for(int i=0; i<n; i++){
        printf("\n\nNº Aluno : %d", a[i].num);
        printf("\nAcertos : %d", a[i].acertos);
    }
    printf("\n");

    return 0;
}
