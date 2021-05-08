#include <stdio.h>

int main() {
	int i=0;
	while (i<=20)
	{
		i++;
		if ( i == 2 ) continue;
			if ( i == 5 ) break;
				printf("i = %d\n",i);
		
	}
	
}
