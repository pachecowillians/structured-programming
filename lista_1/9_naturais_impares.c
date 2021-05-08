#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Digite o N: ");
	scanf("%d",&n);
	for (int i = 1; i < n*2; i+=2)
	{
		if (i+1==n*2)
			printf("%d ",i);
		else
			printf("%d, ",i);
		
	}
	printf("\n");
}