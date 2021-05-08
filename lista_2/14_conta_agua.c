#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int opcao, conta;
	float gasto, total=0;
	printf("Digite o número da conta: ");
	scanf("%d", &conta);
	printf("Digite o número de m³ gastos: ");
	scanf("%f", &gasto);
	printf("\nMenu : \n");
	printf("1 - Residencial  \n");
	printf("2 - Comercial  \n");
	printf("3 - Industrial  \n\n");
	do
	{
		printf("Selecione a opção: ");
		scanf("%d", &opcao);
	} while (opcao!= 1 && opcao != 2 && opcao!=3);

	if (opcao == 1)
		total = 10 + 0.05*gasto;
	else if (opcao == 2){
		if (gasto<=80)
			total = 700;
		else
			total = 700 + 0.25*(gasto-80);
	}else if (opcao == 3){
		if (gasto<=150)
			total = 1200;
		else
			total = 1200 + 0.04*(gasto-150);
	}

	printf("O cliente de conta %d pagará %.2f reais.\n", conta, total);
	return 0;
}