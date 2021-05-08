#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 //compilar com gcc 11_funcao.c -lm && ./a.out
int main(){
	float x,r;
	printf("Digite o núero de x: ");
	scanf("%f", &x);
	if (x<1)
		r = x;
	else if (x==1)
		r = 0;
	else if (x>1)
		r = pow(x,2);

	printf("%.2f\n", r);
	return 0;
}