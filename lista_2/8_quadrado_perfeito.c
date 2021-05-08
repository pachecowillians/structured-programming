#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int num;
	printf("Digite o número: ");
	scanf("%d",&num);	

	if ((int)sqrt(num) == sqrt(num))
		printf("Raiz exata: %.0f (Quadrado perfeito)\n", sqrt(num));
	else
		printf("Raiz não exata: %.2f (Não é quadrado perfeito)\n", sqrt(num));
}