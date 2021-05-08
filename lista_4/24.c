#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void ImprimirFloat(float *v, int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%.1f\n", v[i]);
	}
	printf("\n");
}

void ImprimirInt(int *v, int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", v[i]);
	}
	printf("\n");
}

void ImprimirChar(char **v, int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%s\n", v[i]);
	}
	printf("\n");
}

void CalculaTotalVendas(int *qtd_prod_vend, float *valor_prod, float *valor_tot_vendas, int n){
	for (int i = 0; i < n; ++i)
	{
		valor_tot_vendas[i] = valor_prod[i]*qtd_prod_vend[i];
	}
}

void MaisMenosVendido(int *qtd_prod_vend, char **prod_vendido, int n){
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if (qtd_prod_vend[i]>max)
		{
			max = i;
		}
		if (qtd_prod_vend[i]<min)
		{
			min = i;
		}
	}
	printf("Mais vendido: %s\n", prod_vendido[max]);
	printf("Menos vendido: %s\n", prod_vendido[min]);
}

float TotalArrecadado(float *valor_tot_vendas, int n){
	float soma=0;
	for (int i = 0; i < n; ++i)
		soma+=valor_tot_vendas[i];
	return soma;
}

void main(void) {
	char **prod_vendido;
	int *qtd_prod_vend;
	float *valor_prod, *valor_tot_vendas;


	prod_vendido = malloc(10*sizeof(char));
	for (int i = 0; i < 10; ++i)
		prod_vendido[i] = malloc(30*sizeof(char));
	qtd_prod_vend = malloc(10*sizeof(int));
	valor_prod = malloc(10*sizeof(float));
	valor_tot_vendas = malloc(10*sizeof(float));

	prod_vendido[0] = "Banana"; 
	prod_vendido[1] = "Maca";
	prod_vendido[2] = "alface";
	prod_vendido[3] = "peixe";
	prod_vendido[4] = "carne";
	prod_vendido[5] = "celular";
	prod_vendido[6] = "pepino";
	prod_vendido[7] = "notebook";
	prod_vendido[8] = "teclado";
	prod_vendido[9] = "guitarra";


	qtd_prod_vend[0] = 1;
	qtd_prod_vend[1] = 2;
	qtd_prod_vend[2] = 3;
	qtd_prod_vend[3] = 4;
	qtd_prod_vend[4] = 5;
	qtd_prod_vend[5] = 6;
	qtd_prod_vend[6] = 7;
	qtd_prod_vend[7] = 8;
	qtd_prod_vend[8] = 9;
	qtd_prod_vend[9] = 10;

	valor_prod[0] = 10;
	valor_prod[1] = 10;
	valor_prod[2] = 10;
	valor_prod[3] = 10;
	valor_prod[4] = 10;
	valor_prod[5] = 10;
	valor_prod[6] = 10;
	valor_prod[7] = 10;
	valor_prod[8] = 10;
	valor_prod[9] = 10;

	ImprimirChar(prod_vendido, 10);
	ImprimirInt(qtd_prod_vend, 10);
	ImprimirFloat(valor_prod, 10);

	CalculaTotalVendas(qtd_prod_vend, valor_prod, valor_tot_vendas, 10);	
	printf("Valor total de vendas: \n");
	ImprimirFloat(valor_tot_vendas,10);

	MaisMenosVendido(qtd_prod_vend, prod_vendido, 10);

	printf("Total arrecadado: %.2f\n", TotalArrecadado(valor_tot_vendas, 10));

	free(qtd_prod_vend);	
	free(valor_prod);
	free(valor_tot_vendas);	
}