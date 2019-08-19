#include<stdio.h>

struct person
{
	char name[20];
	double age;
	char sex;
	char phone[16];
};

int main()
{
	struct person p1;
	printf("%d\n",sizeof(p1));
	return 0;
}
