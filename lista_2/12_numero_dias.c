#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int mes, ano, bissexto=0,diasAno=0, diasMes=0;

	printf("Digite o mês: ");
	scanf("%d", &mes);
	printf("Digite o ano: ");
	scanf("%d", &ano);

	if (ano%4==0)
	{
		if (ano%100==0)
		{
			if (ano%400==0)
			{
				bissexto = 1;
			}
			else{
				bissexto = 0;
			}
		}else{
			bissexto = 1;
		}
	}

	diasAno = 365;
	switch(mes){
		case 1:
		diasMes = 31;
		break;
		case 2:
		diasMes = 28;
		break;
		case 3:
		diasMes = 31;
		break;
		case 4:
		diasMes = 30;
		break;
		case 5:
		diasMes = 31;
		break;
		case 6:
		diasMes = 30;
		break;
		case 7:
		diasMes = 31;
		break;
		case 8:
		diasMes = 31;
		break;
		case 9:
		diasMes = 30;
		break;
		case 10:
		diasMes = 31;
		break;
		case 11:
		diasMes = 30;
		break;
		case 12:
		diasMes = 31;
		break;
	}

	if (bissexto==1)
	{
		diasAno = 366;
		if (mes == 2)
		{
			diasMes = 29;
		}		
	}

	printf("Dias no mês: %d\n", diasMes);
	printf("Dias no ano: %d\n", diasAno);

	return 0;
}