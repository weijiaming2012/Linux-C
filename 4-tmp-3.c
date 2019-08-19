#include<stdio.h>

int main()
{
	int a[2][4]={1,2,3,4,5,6,7,8},i;
	int *p1[2]=a,**p2=a,(*p3)[4]=a;
	for(i=0;i<2;i++)
	{
		for(p1[i]=a[i];p1[i]<a[i]+4;)
		{
			printf("%d ",*p1[i]++);
		}
		printf("\n");
	}
	return 0;
}
