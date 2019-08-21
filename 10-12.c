#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>
#include<string.h>

#define BUF_SIZE 256
#define PROJ_ID 32
#define PATH_NAME "."

void getmsgattr(int msgid,struct msqid_ds msq_info);

int main()
{
	/*用户自定义消息缓冲区*/
	struct mymsgbuf{
		long msgtype;
		char ctrlstring[BUF_SIZE];
	}msgbuffer;

	int qid;   /*消息队列标识符*/
	int msglen;
	key_t msgkey;
	struct msqid_ds msq_attr;

	/*获取键值*/
	if((msgkey=ftok(PATH_NAME,PROJ_ID))==-1)
	{
		perror("ftok error!\n");
		exit(1);
	}
	/*获取消息队列标识符*/
	if((qid=msgget(msgkey,IPC_CREAT|0666))==-1)
	{
		perror("msgget error!\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);  /*输出消息队列的属性*/

	/*发送一条消息到消息队列*/
//	msgbuffer.msgtype=2;
//	strcpy(msgbuffer.ctrlstring,"Another message");
//	msglen=sizeof(struct mymsgbuf)-4;
//	if(msgsnd(qid,&msgbuffer,msglen,0)==-1)
//	{
//		perror("msgsnd error!\n");
//		exit(1);
//	}
//	getmsgattr(qid,msq_attr);  /*再输出消息队列的属性*/

	/*设置消息队列的属性*/
	msq_attr.msg_perm.uid=3;
	msq_attr.msg_perm.gid=2;
	if(msgctl(qid,IPC_SET,&msq_attr)==-1)
	{
		perror("msg set error!\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);  /*修改后再观察其属性*/
	if(msgctl(qid,IPC_RMID,NULL)==-1)
	{
		perror("delete msg error!\n");
		exit(1);
	}
	getmsgattr(qid,msq_attr);
	exit(0);
}

void getmsgattr(int msgid,struct msqid_ds msg_info)
{
	if(msgctl(msgid,IPC_STAT,&msg_info)==-1)
	{
		perror("msgctl error!\n");
		return ;
	}
	printf("******information of message queue*******\n");
//	printf("last msgsnd to msq time is %s\n",ctime(&(msg_info.msg_stime)));
//	printf("current number of bytes on queue is %d\n",msg_info.msg_cbytes);
	printf("number of messages in queue is %d\n",msg_info.msg_qnum);
	printf("max number of bytes on queue is %d\n",msg_info.msg_qbytes);
	printf("pid of last msgsnd is %d\n",msg_info.msg_lspid);
	printf("pid of last msgrcv is %d\n",msg_info.msg_lrpid);

	printf("msg uid is %d\n",msg_info.msg_perm.uid);
	printf("msg gid is %d\n",msg_info.msg_perm.gid);
	printf("************information end!********************\n");
}
