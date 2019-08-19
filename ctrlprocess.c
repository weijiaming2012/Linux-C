#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int n;
	char buf[1024];

	while(1)
	{
		if((n=read(stdin,buf,1024))>0)
		{
			buf[n]='\0';
			printf("ctrlprocess recrive: %s\n",buf);

			if(!strcmp(buf,"exit"))
			{
				exit(0);
			}
			if(!strcmp(buf,"getpid"))
			{
				printf("My pid:%d\n",getpid());
				sleep(3);
				exit(0);
			}
		}
	}
	return 0;
}
