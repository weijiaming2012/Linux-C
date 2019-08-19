#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<error.h>

extern int errno;

int main()
{
	int fd;

	printf("uid study:\n");
	printf("Process's uid=%d,euid=%d\n",getuid(),geteuid());

	//strerror函数获取指定错误码的提示信息
	if((fd=open("test.c1",O_RDWR))==-1)
	{
		printf("Open failure,error is %d:%s\n",errno,strerror(errno));
		exit(1);
	}

	else
	{
		printf("Open successfully!\n");
	}

	close(fd);
	exit(0);

	return 0;
}
