#include<stdio.h>
#include<string.h>

void test()
{
	static int a=111;
	printf("%d\n",a++);
}

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

<<<<<<< HEAD
	char ss[20]={'a','c','\0','o'};
	printf("%d %d\n",strlen(ss),sizeof(ss));
=======
	test();
	test();
	test();

	int test1=10,test2=15;
	if(test1>2)
	{
		printf("test1");
	}
	else if(test2<20)
	{
		printf("test2");
	}
>>>>>>> dev
	return 0;
}
