#include <stdio.h>
#include <stdlib.h>

int forma(int a, int b, int c){
	if((a<(b+c) && (b<(a+c)) && (c<(b+a))))
		return 1;
	else
		return 0;
}

int main(void){
	int a,b,c;
	printf("Digite a: ");
	scanf("%d",&a);
	printf("Digite b: ");
	scanf("%d",&b);
	printf("Digite c: ");
	scanf("%d",&c);
	if(forma(a,b,c)==1){
		printf("Forma\n");
		if ((a==b) && (b==c))
			printf("Equilátero\n");
		else if((a!=b) && (b!=c) && (a!=c))
			printf("Escaleno\n");
		else
			printf("Isósceles\n");
	}
	else
		printf("Não forma\n");

}