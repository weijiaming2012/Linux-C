#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	int fd;
	if((fd=open("6-1.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1)
	{
		perror("open");
		exit(0);
	}
	else
	{
		printf("create file success\n");
	}
	close(fd);
	return 0;
}
