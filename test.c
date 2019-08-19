#include<stdio.h>
#include<string.h>

int main()
{
	float a=0.0;
	if(a==0.0)
	{
		printf("111111");
	}
	printf("%d\n",a);

	char str[]={'a','b','c'};
	char *p=str;
	printf("%s\n",p);
	printf("%c\n",p[0]);
	char str2[]="abc";
	p=str2;
	printf("%s\n",p);
	printf("%c\n",*p);

	char *s="abcdefgh123";
	printf("%d %d\n",strlen(s),sizeof(s));
	return 0;
}
