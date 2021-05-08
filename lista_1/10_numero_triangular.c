#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n,i=0;
	printf("Digite o número: ");
	scanf("%d", &n);
	do
	{
		i++;
		if (i*(i+1)*(i+2)==n)
			printf("É triangular: %d.%d.%d = %d\n", i,i+1,i+2,n);
		else if(i>sqrt(n))
			printf("Não é triangular!\n");
	} while (i <= sqrt(n) && i*(i+1)*(i+2)!=n);
}