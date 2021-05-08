#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcatW(char *s1, char *s2, char *sres){
	int cont, i;
    for (i = 0; i < strlen(s1); ++i){
	    sres[i] = s1[i];
    }
    cont = i;
	for (i = cont; i < cont+strlen(s2); ++i)
	    sres[i] = s2[i-cont];
}

int main(){

	char s1[50] = "Willian";
	char s2[50] = "Pacheco";
	char sres[150] = "";

	strcatW(s1, s2, sres);

	printf("%s\n", sres);

}
