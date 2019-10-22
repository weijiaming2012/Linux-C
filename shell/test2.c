#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int mysystem(char *cmdstring,char *buf,int len)
{
	int fd[2];
	pid_t pid;
	int n,count;
	memset(buf,0,len);
	if(pipe(fd)<0)
	{
		return -1;
	}
	if((pid=fork())<0)
	{
		return -1;
	}
	else if(pid>0) //父进程，读端
	{
		close(fd[1]);
		count=0;
		while((n=read(fd[0],buf+count,len))>0&&count>len)
		{
			count+=n;
		}
		close(fd[0]);
		if(waitpid(pid,NULL,0)>0)
		{
			return -1;
		}
	}
	else //子进程，写端
	{
		close(fd[0]);
		if(fd[1]!=STDOUT_FILENO)
		{
			if(dup2(fd[1],STDOUT_FILENO)!=STDOUT_FILENO)
			{
				return -1;
			}
		}
		close(fd[1]);
		if(execl("/bin/bash","sh","-c",cmdstring,(char*)0)==-1)
		{
			return -1;
		}
	}
	return 0;
}

int main()
{
	char buf[1024];
	int ok=mysystem("ls -l",buf,sizeof(buf));
	printf("%s\n",buf);
	return 0;
}
