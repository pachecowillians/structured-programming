#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void main(void) {
	int x=1, *px;
	float y=2, *py;
	char z='3', *pz;
	printf("Antes-->\n");
	printf("x = %d; &x = %p; *px = %d; px = %p\n", x,&x,*px,px);
	printf("y = %.1f; &y = %p; *py = %.1f; py = %p\n", y,&y,*py,py);
	printf("z = %c; &z = %p; *pz = %c; pz = %p\n", z,&z,*pz,pz);

	px = &x;
	py = &y;
	pz = &z;

	x += 2;
	y += 2;
	z = '2';

	*px *= 2;
	*py *= 2;
	*pz = 'P';
	printf("Depois-->\n");
	printf("x = %d; &x = %p; *px = %d; px = %p\n", x,&x,*px,px);
	printf("y = %.1f; &y = %p; *py = %.1f; py = %p\n", y,&y,*py,py);
	printf("z = %c; &z = %p; *pz = %c; pz = %p\n", z,&z,*pz,pz);


}