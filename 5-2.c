#include<stdio.h>
#define MAX(x,y) (x>y?x:y)

int main()
{
	int a=5,b=10,max;
	max=MAX(a,b);
	printf("max is %d\n",max);
	return 0;
}
