#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	int stat_val=0;
	int oldpri,newpri;

	printf("nice study\n");

	pid=fork();
	switch(pid)
	{
		case 0:
			printf("Child is running,CurPid is %d,ParentPid is %d\n",pid,getppid());
			oldpri=getpriority(PRIO_PROCESS,0);
			printf("Old priority =%d\n",oldpri);
			newpri=nice(2);
			printf("New priority=%d\n",newpri);
			exit(0);
		case -1:
			perror("Process creation failed\n");
			break;
		default:
			printf("Parent is running,ChildPid is %d,ParentPid is %d\n",pid,getpid());
			break;
	}

	wait(&stat_val);
	exit(0);

	return 0;
}
