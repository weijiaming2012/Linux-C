#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

#define FIFO_NAME "myfifo"
#define BUF_SIZE 1024

int main()
{
	int fd;
	char buf[BUF_SIZE];

	umask(0);
	fd=open(FIFO_NMAE,O_RDONLY);
	read(fd,buf,SUF_SIZE);
	printf("Read content :%s\n",buf);
	close(fd);
	return 0;
}
