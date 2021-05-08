#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	char frase[50]="";
	fflush(stdin);
	
	do
	{
		if (strlen(frase)!=0)
			printf("Frase com mais de 40 caracteres! \n");
		printf("Digite a frase: ");
		gets(frase);
	} while (strlen(frase)>40);
	

	for (int i = 0; i < strlen(frase); ++i)
	{
		printf("%c\n", frase[i]);
		getchar(); //ou system("pause")
	}
	return 0;
}
