#include<stdio.h>

int main()
{
	int i,j,sum=0;
	for(i=1;i<=10;i++)
	{
		int total=1;
		for(j=1;j<=i;j++)
		{
			total*=j;
		}
		sum+=total;
	}
	printf("1!+2!+3!+...+10!=%d\n",sum);
	return 0;
}
