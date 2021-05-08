#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main (void ) {
	int j, *pj;
	pj = &j; //Faltava isso daqui!
	*pj = 3;
	printf("%d",*pj);
}