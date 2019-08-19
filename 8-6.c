#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
	FILE *stream;
	char *filename="test1";

	errno=0;

	stream=fopen(filename,"r");
	if(stream==NULL)
	{
		//printf("open file %s failed,error is %d\n",filename,errno);
		printf("open file %s failed,error is %d\n",filename,strerror(errno));
	}
	else
	{
		printf("open file %d successfully\n",filename);
	}
}
