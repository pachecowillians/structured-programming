#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

struct carro{
	char marca[15], modelo[20], cambio[20];
	int ano;
	float preco;
};

int main()
{
	struct carro c[5];
	for (int i = 0; i < 5; ++i)
	{	__fpurge(stdin);
		printf("Digite a marca do carro %d: ", i+1);
		scanf("%[^\n]", c[i].marca);
		__fpurge(stdin);
		printf("Digite o modelo do carro %d: ", i+1);
		scanf("%[^\n]", c[i].modelo);
		__fpurge(stdin);
		printf("Digite o cambio do carro %d: ", i+1);
		scanf("%[^\n]", c[i].cambio);
		__fpurge(stdin);
		printf("Digite o ano do carro %d: ", i+1);
		scanf("%d", &c[i].ano);
		__fpurge(stdin);
		printf("Digite o preço do carro %d: ", i+1);
		scanf("%f", &c[i].preco);
	}
	for (int i = 0; i < 5; ++i)
	{
		printf("\nMarca : %s", c[i].marca);
		printf("\nModelo : %s", c[i].modelo);
		printf("\nCambio : %s", c[i].cambio);
		printf("\nAno : %d", c[i].ano);
		printf("\nPreço : %.2f\n", c[i].preco);
	}

	return 0;
}
