#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char experiencia[1], opcao[1];
	float idade, contM=0, contF=0, contFExp=0, idadeMediaH=0, idadeMediaM=0, contHIdade=0, menIdadeM=0, ef=0, em=0, g=0, pg=0;
	int sexo, escolaridade;
	do
	{
		printf("\nSexo: \n");
		printf("1 - Masculino\n");
		printf("2 - Feminino\n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &sexo);

		printf("\nDigite a idade: ");
		scanf("%f", &idade);
		printf("O usuário já tem experiência na área?: (s/n)");
		scanf("%s", experiencia);

		printf("\nNível de escolaridade: \n");
		printf("1 - Ensino Fundamental\n");
		printf("2 - Ensino Médio\n");
		printf("3 - Graduação\n");
		printf("4 - Pós Graduação\n\n");
		printf("Escolha uma opção: ");
		scanf("%d",&escolaridade);

		if (sexo == 1){
			contM++;
			idadeMediaH+=idade;
			if (idade>=35 && idade<=45)
				contHIdade++;
		}
		else if(sexo == 2){
			contF++;
			if(strcmp("s",experiencia)==0 || strcmp("S",experiencia)==0)
				idadeMediaM+=idade;
				contFExp++;
			if (menIdadeM==0)
				menIdadeM = idade;
			else if(idade<menIdadeM)
				menIdadeM = idade;
		}

		switch(escolaridade){
			case 1:
			ef++;
			break;
			case 2:
			em++;
			break;
			case 3:
			g++;
			break;
			case 4:
			pg++;
			break;
		}


		printf("\nDeseja cadastrar outro candidato? (s/n)");
		scanf("%s", opcao);
	} while (strcmp(opcao,"n")!=0 && strcmp(opcao,"N")!=0);


	printf("\nNumero de candidatos homens: %.0f\n", contM);
	printf("Numero de candidatas mulheres: %.0f\n", contF);
	printf("Idade média dos homens: %.2f\n", idadeMediaH/contM);
	printf("Idade média das mulheres com experiência: %.2f\n", idadeMediaM/contFExp);
	printf("Porcentagem de homens com idade entre 35 e 45 anos: %.2f\n", (contHIdade*100)/contM);
	printf("Menor idade entre as mulheres que já tem experiência: %.2f\n", menIdadeM);
	printf("Nível de escolaridade: \n");
	printf("- Ensino Fundamental: %.0f\n", ef);
	printf("- Ensino Médio: %.0f\n", em);
	printf("- Graduação: %.0f\n", g);
	printf("- Pós Graduação: %.0f\n\n", pg);

}