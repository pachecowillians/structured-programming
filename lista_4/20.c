#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void main(void) {
	int x,y;
	scanf("%d", &x);
	scanf("%d", &y);

	if (&x>&y)
		printf("%d %x\n",x, &x);
	else
		printf("%d %x\n",y, &y);
}