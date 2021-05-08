#include <stdio.h>
#include <stdlib.h>

int soma(){
	int i, n, somas = 0;

	for (int i = 0; i < 10; ++i)
	{
		printf("Digite %d: ",i);
		scanf("%d",&n);
		somas += n;
	}
	return somas;
}

int main(void){
	printf("Soma: %d\n", soma());
}