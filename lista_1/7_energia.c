#include <stdio.h>
#include <stdlib.h>

int main(void){
	float salario=0, kw=0,precoKw=0;
	printf("Salário mínimo: ");
	scanf("%f", &salario);
	printf("Quilowatts: ");
	scanf("%f", &kw);

	precoKw = (salario/8)/100;

	printf("Preço de cada KW: %f\n", precoKw);
	printf("Valor a ser pago: %f\n",precoKw*kw);
	printf("Valor a ser pago: %f\n",(precoKw*kw)*0.85);


}