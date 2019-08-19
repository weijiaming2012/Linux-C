#include<stdio.h>

int main()
{
	int i,sum=0;
	for(i=1;i<=100;i++,i++)
	{
		sum+=i;	
	}
	printf("1+3+5+...+99=%d\n",sum);
	return 0;
}
