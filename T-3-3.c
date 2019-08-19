#include<stdio.h>

int main()
{
	int sum=0,step=3,flag=0;
	while(1)
	{
		sum=(step%2==1)+(step%3==2)+(step%5==4)+(step%6==5)+(step%7==0);
		if(sum==5)
		{
			flag=1;
			printf("The step is %d\n",step);
			break;
		}
		step++;
	}
	if(flag==0)
	{
		printf("Can not!\n");
	}
	return 0;
}
