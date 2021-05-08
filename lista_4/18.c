#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void proc(int *px, int *py) {
	*py = (*py) * (*px);
	*px = *px + 2;
}

void main(void) {
	int x, y;
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%p %p\n", &x, &y);
	proc(&x,&y);
	printf("x = %d, y = %d", x, y);
}