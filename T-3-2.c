#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int number,guess,i;
	srand(time(NULL));
	number=rand()%100+1;
	printf("Please guess a number:\n");
	for(i=0;i<8;i++)
	{
		scanf("%d",&guess);
		if(guess==number)
		{
			printf("Wonderful,you are right!\n");
			break;
		}
		if(guess>number)
		{
			printf("Sorry,you are wrong!");
			printf("too high!\n");
		}
		if(guess<number)
		{
			printf("Sorry,you are wrong!");
			printf("too low!\n");
		}
	}
	return 0;
}
