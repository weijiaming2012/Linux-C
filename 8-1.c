#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int *thread(void *arg)
{
	pthread_t newthid;
	newthid=pthread_self();
	sleep(3);
	printf("this is a new thread,thread ID=%u\n",newthid);
	return NULL;
}

int main(void)
{
	pthread_t thid;

	printf("main thread,ID is %u\n",pthread_self());
	if(pthread_create(&thid,NULL,(void *)thread,NULL)!=0)
	{
		printf("thread creation failed\n");
		exit(1);
	}
	printf("main thread end\n");
	sleep(1);
	exit(0);
}
