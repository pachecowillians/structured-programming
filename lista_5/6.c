#include <stdio.h>
#include <stdlib.h>

void ler (char str[], int pos){
	FILE *arq = fopen("arquivoString.txt", "r+");
	fseek(arq, pos, SEEK_SET);
	fscanf(arq, "%[^\n]", str);
	fclose(arq);
}

int main(){
	char str[30];
	FILE *arq = fopen("arquivoString.txt", "w+");
	fprintf(arq, "Esse é meu teste");
	fclose(arq);
	ler(str,8);
	printf("%s", str);

}
