#include<stdio.h>
#include<string.h>

int main()
{
	struct student
	{
		int number;
		char name[20];
		char sex;
		int age;
		char addr[20];
	};
	struct student s[3]={
		{10000,"Zhang",'m',21,"Shang Hai"},
		{10001,"Li",'f',20,"Bei Jing"}
	};
	s[2].number=10002;
	s[2].sex='m';
	s[2].age=22;
	strcpy(s[2].name,"Liu");
	strcpy(s[2].addr,"Guang Dong");

	printf("%d,%s,%c,%d,%s\n",s[2].number,s[2].name,s[2].sex,s[2].age,s[2].addr);

	return 0;
}
