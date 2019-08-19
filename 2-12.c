#include<stdio.h>

int main()
{	
	int a=1, b=2,temp;
	temp=a;
	a=b;
	b=temp;
	printf("%d %d\n",a,b);

	a=a+b;
	b=a-b;
	a=a-b;
	printf("%d %d\n",a,b);

	return 0;
}
