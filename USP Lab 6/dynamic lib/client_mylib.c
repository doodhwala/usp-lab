#include <stdio.h>
#include "mylib.h"

int main()
{
	int a = 1, b = 2;
	
	printf("a + b = %d\n", add(a, b));
	printf("a - b = %d\n", sub(a, b));
	printf("a * b = %d\n", mul(a, b));
}
