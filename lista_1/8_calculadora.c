#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float soma(float a, float b){
	return a+b;
}
float subtracao(float a, float b){
	return a-b;
}
float multiplicacao(float a, float b){
	return a*b;
}
float divisao(float a, float b){
	return a/b;
}

int main(void){
	float a,b;
	char op[2];

	system("clear");

	printf("Digite o primeiro número: ");
	scanf("%f",&a);
	printf("Digite a operação: ");
	scanf("%s", op);
	
	do
	{
		printf("Digite o segundo número: ");
		scanf("%f",&b);

		if((strcmp(op,"/")==0) && b==0)
			printf("Não pode dividir por zero!\n");
	} while ((b==0 && strcmp(op,"/")==0));

	if(strcmp(op,"+")==0)
		printf("Resultado: %.2f\n", soma(a,b));
	else if(strcmp(op,"-")==0)
		printf("Resultado: %.2f\n", subtracao(a,b));
	else if(strcmp(op,"*")==0)
		printf("Resultado: %.2f\n", multiplicacao(a,b));
	else if(strcmp(op,"/")==0)
		printf("Resultado: %.2f\n", divisao(a,b));
}