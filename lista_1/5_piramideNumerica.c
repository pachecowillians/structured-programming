#include <stdio.h>
#include <stdlib.h>

void printPiramide(int fim){
	int inicio = 1;
	while(inicio!=fim){
		for (int i = 0; i < inicio; ++i)
		{
			printf(" ");
		}
		for (int i = inicio; i <= fim; ++i)
		{
			printf("%d",i);
		}
		printf("\n");
		inicio++;
		fim--;
	}
	for (int i = 0; i < inicio; ++i)
	{
		printf(" ");
	}
	printf("%d\n",inicio);

}
int main(void){
	printPiramide(17);
}