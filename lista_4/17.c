#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void soma(int k){
	k=k+1;
}
void adiciona(int x){
	x=x+1;
}
void incrementa(int *k){
	*k=*k+1;
}

int main (void){
	int x;
	printf("Digite o valor de X: ");
	scanf("%d",&x);
	incrementa(&x);
	printf("X= %d",x);
}