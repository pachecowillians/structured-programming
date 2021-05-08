#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct{
	char sexo[20], cor_olhos[40], cor_cabelos[50];
	int idade;
}Populacao;

int main(){
	system("clear");
	Populacao p[50];
	int sexo, cor_olhos, cor_cabelos, maiIdade=0, contIndEntreIdade=0, contVerdeLoiro=0;
	for (int i = 0; i < 50; ++i)
	{
		__fpurge(stdin);
		printf("Digite o sexo: \n");
		printf("1 - Masculino\n");
		printf("2 - Feminino\n");
		scanf("%d", &sexo);
		__fpurge(stdin);
		printf("Digite a cor dos olhos: \n");
		printf("1 - Azuis\n");
		printf("2 - Verdes\n");
		printf("2 - Castanhos\n");
		scanf("%d", &cor_olhos);
		printf("Digite a cor dos cabelos: \n");
		printf("1 - Louros\n");
		printf("2 - Castanhos\n");
		printf("2 - Pretos\n");
		scanf("%d", &cor_cabelos);
		printf("Digite a idade: ");
		scanf("%d", &p[i].idade);
		switch(sexo){
			case 1:
				strcpy(p[i].sexo,"masculino");
				break;
			case 2:
				strcpy(p[i].sexo,"feminino");
				break;
		}

		switch(cor_olhos){
			case 1:
				strcpy(p[i].cor_olhos,"azuis");
				break;
			case 2:
				strcpy(p[i].cor_olhos,"verdes");
				break;
			case 3:
				strcpy(p[i].cor_olhos,"castanhos");
				break;
		}
		switch(cor_cabelos){
			case 1:
				strcpy(p[i].cor_cabelos,"louros");
				break;
			case 2:
				strcpy(p[i].cor_cabelos,"castanhos");
				break;
			case 3:
				strcpy(p[i].cor_cabelos,"pretos");
				break;
		}

		if (p[i].idade>maiIdade)
		{
			maiIdade = p[i].idade;
		}
		if (strcmp(p[i].sexo,"feminino")==0 && p[i].idade>=18 && p[i].idade<=35)
		{
			contIndEntreIdade++;
		}
		if (strcmp(p[i].cor_olhos,"verdes")==0 && strcmp(p[i].cor_cabelos,"louros")==0 )
		{
			contVerdeLoiro++;
		}
	}

	printf("Maior idade: %d\n", maiIdade);
	printf("Mulheres com idades entre 18 e 35 anos, inclusive: %d\n", contIndEntreIdade);
	printf("Indivíduos com olhos verdes e cabelos louros: %d\n", contVerdeLoiro);

}
	