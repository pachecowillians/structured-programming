#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int num1, num2;
	printf("Digite o primeiro número: ");
	scanf("%d", &num1);
	printf("Digite o segundo número: ");
	scanf("%d", &num2);
	if (num1>num2)
	{
		for (int i = num1; i >= num2; --i)
		{
			printf("%d\n", i);
		}
	}else if (num1<num2)
	{
		for (int i = num1; i <= num2; ++i)
		{
			printf("%d\n", i);
		}
	}else 
		printf("Números iguais \n");
}