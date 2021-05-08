#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void frac(float num, int *inteiro, float *frac){
	*inteiro = num;
	*frac = num-*inteiro;

}

void main(void) {
	int inteiro;
	float fracionario;
	frac(12.03, &inteiro, &fracionario);

	printf("Inteiro : %d\n", inteiro);
	printf("Fracionario : %.4f\n", fracionario);

	
}