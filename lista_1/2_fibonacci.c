#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
	if (n<=1)
		return 0;
	else if(n==2)
		return 1;
	else 
		return fibonacci(n-1) + fibonacci(n-2);
}
void printW(int n){
	int i;
	for (i = 1; i < n; ++i)
	{
		if (i+1==n)
			printf("%d\n", fibonacci(i));
		else
			printf("%d,", fibonacci(i));
	}
}
int main(void){
	printW(10);
}