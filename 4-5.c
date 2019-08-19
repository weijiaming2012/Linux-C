#include<stdio.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	extern i,j;
	printf("%d\n",max(i,j));
	return 0;
}

int i=-5,j=10;
