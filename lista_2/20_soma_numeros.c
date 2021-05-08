#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	
	int j=0,n1=0,n2=0,n3=0;
	
	for (int i = 100; i <= 999; i++)
	{
		j++;
		if (j>20)
		{
			printf("Pressione alguma tecla para continuar: ");
			getchar();
			j=0;
		}
			n1 = i/100;
			n2 = (i%100)/10;
			n3 = ((i%100)%10);
			printf("%d (%d*%d*%d)\n",(n1*n2*n3),n1,n2,n3);
	}
}
