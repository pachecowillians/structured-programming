#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> //bibilioteca para o __fpurge
#include <math.h>

int main()
{
	char p[10], f[70];
	int deslocador=0, erro=0, cont=0;
	__fpurge(stdin);
	printf("Digite a palavra: ");
	scanf("%[^\n]", p);
	__fpurge(stdin);
	printf("Digite a frase: ");
	scanf("%[^\n]", f);


	for (int j = 0; j < strlen(f)-strlen(p)+1; j++)
	{
		erro=0;
		for (int i = 0; i < strlen(p); i++)
		{
			if (p[i]!=f[i+deslocador])
			{
				erro=1;
			}
		}
		if (erro==0)
		{
			cont++;
		}
		
		deslocador++;
	}

	printf("\nOcorrem %d vezes\n", cont);

	return 0;
}
