#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void numCaracteres(char *s){
	printf("Numero de caracteres: %d\n", strlen(s));
}
void numPontuacao(char *s){
	int c=0;
	for (int i = 0; i < strlen(s); ++i)
		if(ispunct(s[i])!=0)
			c++;
	printf("Numero de pontuacao: %d\n", c);
}

void numNumeros(char *s){
	int c=0;
	for (int i = 0; i < strlen(s); ++i)
		if(isdigit(s[i])!=0)
			c++;
	printf("Numero de Números: %d\n", c);
}

void numMinusculas(char *s){
	int c=0;
	for (int i = 0; i < strlen(s); ++i)
		if(islower(s[i])!=0)
			c++;
	printf("Numero de Minúsculas: %d\n", c);
}

void numMaiusculas(char *s){
	int c=0;
	for (int i = 0; i < strlen(s); ++i)
		if(isupper(s[i])!=0)
			c++;
	printf("Numero de Maiúsculas: %d\n", c);
}

void numEspacos(char *s){
	int c=0;
	for (int i = 0; i < strlen(s); ++i)
		if(isspace(s[i])!=0)
			c++;
	printf("Numero de Espaços: %d\n", c);
}

void menu(char *s){
	int op;
	do
	{
		printf("0 - Sair\n");
		printf("1 - Numero de caracteres\n");
		printf("2 - Numero de caracteres de pontuação\n");
		printf("3 - Numero de caracteres que são numeros\n");
		printf("4 - Numero de caracteres que são letras minúsculas\n");
		printf("5 - Numero de caracteres que são letras maiúsculas\n");
		printf("6 - Numero de caracteres que são espaços em branco\n");
		scanf("%d", &op);
		system("clear");
		printf("String : %s\n", s);
		switch(op){
			case 1:
				numCaracteres(s);
				break;
			case 2:
				numPontuacao(s);
				break;
			case 3:
				numNumeros(s);
				break;
			case 4:
				numMinusculas(s);
				break;
			case 5:
				numMaiusculas(s);
				break;
			case 6:
				numEspacos(s);
				break;
		}
	} while (op!=0);
	
}

int main(){
	system("clear");
	char nome[100];

	printf("Digite a string: ");
	__fpurge(stdin);
	scanf("%[^\n]", nome);
	menu(nome);
	
}