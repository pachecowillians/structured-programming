#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	char opcao[1];
	int  olho, cabelo, sexo;
	float cont =0, idade, contM=0, contF=0, contOlhoVerde=0, contOlhoAzul=0, contOlhoCastanho=0, contCabeloLouro=0, contCabeloCastanho=0, contCabeloPreto=0;
	float altura, peso, mediaIdade=0, mediaPeso=0, mediaAltura=0;

	do
	{
		do
		{
			printf("\nSelecione o sexo: ");
			printf("\n1 - Masculino ");
			printf("\n2 - Feminino ");
			printf("\n\nDigite a opção: ");
			scanf("%d", &sexo);
		} while (sexo!=1 && sexo!=2);

		do
		{
			printf("Selecione a cor dos olhos: ");
			printf("\n1 - Azuis ");
			printf("\n2 - Verdes ");
			printf("\n3 - Castanhos ");
			printf("\n\nDigite a opção: ");
			scanf("%d", &olho);
		} while (olho!=1 && olho!=2 && olho!=3);

		do
		{
			printf("Digite a cor dos cabelos: ");
			printf("\n1 - Louros ");
			printf("\n2 - Castanhos ");
			printf("\n3 - Pretos ");
			printf("\n\nDigite a opção: ");
			scanf("%d", &cabelo);
		} while (cabelo!=1 && cabelo!=2 && cabelo!=3);
		
		
		printf("Digite a idade: ");
		scanf("%f", &idade);
		printf("Digite a altura: ");
		scanf("%f", &altura);
		printf("Digite o peso: ");
		scanf("%f", &peso);

		cont++;

		mediaIdade+=idade;
		mediaAltura+=altura;
		mediaPeso+=peso;

		if (sexo==1)
			contM++;
		else 
			contF++;

		if (olho ==3)
		{
			contOlhoCastanho++;
		}else if (olho==2)
		{
			contOlhoVerde++;
		}else if (olho==1)
		{
			contOlhoAzul++;
		}

		if (cabelo ==1)
		{
			contCabeloLouro++;
		}else if (cabelo ==2)
		{
			contCabeloCastanho++;
		}else if (cabelo ==3)
		{
			contCabeloPreto++;
		}

		printf("Deseja continuar? (s/n) ");
		scanf("%s", opcao);
	} while (strcmp(opcao,"n")!=0);

	mediaPeso = mediaPeso/cont;
	mediaAltura/=cont;
	mediaIdade/=cont;

	printf("\nMédia de idade: %.2f\n", mediaIdade);
	printf("Média de altura: %.2f\n", mediaAltura);
	printf("Média de peso: %.2f\n\n", mediaPeso);

	printf("Percentual de mulheres: %.2f\n", (contF*100/cont)); 
	printf("Percentual de homens: %.2f\n\n", (contM*100/cont));

	printf("Olhos azuis: %.0f\n", contOlhoAzul);
	printf("Olhos verdes: %.0f\n", contOlhoVerde);
	printf("Olhos castanhos: %.0f\n\n", contOlhoCastanho);

	printf("Cabelos louros: %.0f\n", contCabeloLouro);
	printf("Cabelos castanhos: %.0f\n", contCabeloCastanho);
	printf("Cabelos pretos: %.0f\n", contCabeloPreto);


	return 0;
}
