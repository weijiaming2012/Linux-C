#include<stdio.h>

int myabs(int x);

int main()
{
	int x;
	scanf("%d",&x);
	printf("myabs(%d)=%d\n",x,myabs(x));
	return 0;
}

int myabs(int x)
{
	return x>0?x:-x;
}
