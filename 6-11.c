#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//#include<Linux/limits.h>

/*自定义错误处理函数*/
void my_err(const char *err_string,int line)
{
	fprintf(stderr,"line:%d",line);
	perror(err_string);
	exit(1);
}

int main(int argc,char **argv)
{
	char buf[300+1];

	if(argc<2)
	{
		printf("my_cd <target payh>\n");
		exit(1);
	}

	if(chdir(argv[1])<0)
	{
		my_err("chdir",__LINE__);
	}
	if(getcwd(buf,512)<0)
	{
		my_err("getcwd",__LINE__);
	}
	printf("%s\n",buf);

	return 0;
}
