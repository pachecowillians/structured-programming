#include <stdio.h>
#include <stdlib.h>

int main(void){
	float n,total=0,media=0;
	for (int i = 1; i <= 3; ++i)
	{
		printf("Digite a %d nota: ",i);
		scanf("%f",&n);
		total += n;
	}
	media = total/3;
	printf("Média: %f\n", media);
	if(media>=7)
		printf("Aprovado\n");
	else if(media<4)
		printf("Reprovado\n");
	else
		printf("Prova final\n");
}