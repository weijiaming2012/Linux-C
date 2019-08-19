#include<stdio.h>

int max(int x,int y)
{
	return x>y?x:y;
}

int main()
{
	int x,y,m;
	scanf("%d,%d",&x,&y);
	m=max(x,y);
	printf("max=%d\n",m);
	return 0;
}
