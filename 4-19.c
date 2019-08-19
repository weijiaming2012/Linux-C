#include<stdio.h>

static int a;

void f()
{
	printf("%d\n",a);
}

//static int a;

int main()
{
	f();
	return 0;
}
