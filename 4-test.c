#include<stdio.h>

int get_sum(int n)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	return sum;
}

int main()
{
	int i=100,result;
	result=get_sum(i);
	printf("1+2+...+100=%d\n",result);
	return 0;
}
