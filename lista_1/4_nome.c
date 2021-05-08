#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char a[60], b[60];
	int i=0;

	printf("Didite o nome 1: ");
	scanf("%s",a);
	printf("Didite o nome 2: ");
	scanf("%s",b);

	i = (strcmp(a,b));
	
	if(i<0)
		printf("%s\n%s\n",a,b);
	else
		printf("%s\n%s\n",b,a);

}