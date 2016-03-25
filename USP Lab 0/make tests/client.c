#include<stdio.h>
int f1();
int f2();
int add(int, int);

int main()
{
	int a, b, c;
	a = f1();
	b = f2();
	c = add(a,b);
	printf("%d\n", c);
	return 0;
}
