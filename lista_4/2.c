#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strcpyW(char *a, char *b){
	while(*a != '\0'){
		*b = *a;
		b++;
		a++;
	}	
}

int main(){
	char a[30] = "abobora",b[30];	
	strcpyW(a,b);
	printf("A = %s\n", a);
	printf("B = %s\n", b);
}