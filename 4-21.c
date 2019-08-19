#include<stdio.h>

void f()
{
	static int a=3;
	printf("%d\n",a++);
}

int main()
{
	f();
	f();
	return 0;
}
