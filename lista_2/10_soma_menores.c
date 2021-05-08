#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	float n1,n2,n3,n4, maior=0, resultado=0;
	printf("Digite o primeiro número: ");
	scanf("%f", &n1);
	printf("Digite o segundo número: ");
	scanf("%f", &n2);
	printf("Digite o terceiro número: ");
	scanf("%f", &n3);
	printf("Digite o quarto número: ");
	scanf("%f", &n4);

	if (n1>n2)
	{
		if (n1>n3)
		{
			if (n1>n4)
				maior = n1;
			else
				maior = n4;
		}
		else {
			if (n3>n4)
				maior = n3;
			else
				maior = n4;
		}
	} else{
		if (n2>n3)
		{
			if (n2>n4)
				maior = n2;
			else
				maior = n4;
		}
		else {
			if (n3>n4)
				maior = n3;
			else
				maior = n4;
		}
	}

	resultado = n1+n2+n3+n4-maior;

	printf("A soma dos menores é: %.2f\n", resultado);

}