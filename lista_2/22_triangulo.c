#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	float num,val,area;
	printf("Digite o numero de lados: ");
	scanf("%f", &num);
	
	if (num<3)
	{
		printf("NÃO É UM POLÍGONO\n");
	}else if (num>5)
	{
		printf("POLÍGONO NÃO IDENTIFICADO\n");
	}else{
		printf("Digite o valor do lado: ");
		scanf("%f", &val);
		if (num==3)
		{
			printf("TRIÂNGULO\n");
			area = (pow(val,2)*sqrt(3))/4;
			printf("Área = %.2f\n",area);
		}else if (num==4)
		{
			printf("QUADRADO\n");
			area = pow(val,2);
			printf("Área = %.2f\n",area);
		}else if (num==5)
		{
			printf("PENTÁGONO\n");
		}
	}
	
	
	
}

