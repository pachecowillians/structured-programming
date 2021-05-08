#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int x,y,aux;
	printf("Digite o X: ");
	scanf("%d", &x);
	printf("Digite o Y: ");
	scanf("%d", &y);
	aux = x;
	x = y;
	y = aux;
	printf("X = %d\nY = %d\n",x,y);
}
