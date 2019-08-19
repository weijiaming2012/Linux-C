#include<stdio.h>

int main()
{
	int a[2][5]={1,2,3,4,5,6,7,8,9,10};
	int (*p)[5],i;
	p=a;
	for(i=0;i<5;i++)
	{
		printf("%d ",(*p)[i]);
	}
	printf("\n");
	p++;
	for(i=0;i<5;i++)
	{
		printf("%d ",(*p)[i]);
	}
	printf("\n");
	return 0;
}
