#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[40];
	int a=0 ,e=0 ,i=0 ,o=0 ,u=0 ;
	printf("Digite o nome: ");
	scanf("%[^\n]",nome);
	for (int j = 0; j < strlen(nome); ++j)
	{
		switch(nome[j]){
			case 'a':
				a++;
				break;	
			case 'e':
				e++;
				break;	
			case 'i':
				i++;
				break;	
			case 'o':
				o++;
				break;	
			case 'u':
				u++;
				break;	

			case 'A':
				a++;
				break;	
			case 'E':
				e++;
				break;	
			case 'I':
				i++;
				break;	
			case 'O':
				o++;
				break;	
			case 'U':
				u++;
				break;	
			default:
				break;	
		}
	}
	printf("A = %d\nE = %d\nI = %d\nO = %d\nU = %d\n",a,e,i,o,u );

}