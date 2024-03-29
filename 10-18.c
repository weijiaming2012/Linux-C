#include "sharemem.h"
#include<stdlib.h>
#include<string.h>

int main()
{
	int semid,shmid;
	char *shmaddr;
	char write_str[SHM_SIZE];

	if((shmid=createshm(".",'m',SHM_SIZE))==-1)
	{
		exit(1);
	}

	if((shmaddr=shmat(shmid,(char *)0,0))==(char *)-1)
	{
		perror("attach shared memory error\n");
		exit(1);
	}

	if((semid=createsem(".",'s',1,1))==-1)
	{
		exit(1);
	}

	while(1)
	{
		wait_sem(semid,0);

		sem_p(semid,0);

		printf("writer:");
		fgets(write_str,1024,stdin);
		int len=strlen(write_str)-1;
		write_str[len]='\0';
		strcpy(shmaddr,write_str);
		sleep(10);
		sem_v(semid,0);
		sleep(10);
	}

	return 0;
}
