#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int num,cont=0;
	printf("Digite o número: ");
	scanf("%d", &num);	
	for (int i = 1; i < (num/2)+1; ++i)
	{
		if (num%i==0)
		{
			cont+=i;
		}
	}
	if (cont==num)
		printf("O número é perfeito \n");
	else
		printf("O número não é perfeito \n");
}