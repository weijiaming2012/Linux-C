#include<stdio.h>
#include<setjmp.h>
#include<signal.h>
#include<unistd.h>

#define ENV_UNSAVE 0
#define ENV_SAVED 1

int flag_saveenv=ENV_UNSAVE;
jmp_buf env;  //保存带跳转位置的栈信息

/*信号SIGRTMIN+15的处理函数*/
void handler_sigrtmin15(int signo)
{
	if(flag_saveenv==ENV_UNSAVE)
	{
		return ;
	}
	printf("recv SIGRTMIN+15\n");
	sleep(10);
	printf("in handler_sigrtmin15,after sleep\n");
	siglongjmp(env,1);
}

int main()
{
	/*设置返回点*/
	switch(sigsetjmp(env,1))
	{
		case 0:
			printf("return 0\n");
			flag_saveenv=ENV_SAVED;
			break;
		case 1:
			printf("return from SIGRTMIN+15");
			break;
		default:
			printf("return else\n");
			break;
	}

	/*捕捉信号，安装信号处理函数*/
	signal(SIGRTMIN+15,handler_sigrtmin15);

	while(1);

	return 0;
	return 0;
}
