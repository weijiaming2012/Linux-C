#include<stdio.h>
#define CMD_STR_LEN 1024

int mysystem(char *cmdstring,char *tmpfile)
{
	char cmd_string[CMD_STR_LEN];
	mkstemp(tmpfile);
	sprintf(cmd_string,"%s > %s",cmdstring,tmpfile);
	return system(cmd_string);
}

int main()
{
	int ok=mysystem("uname -a","tmp.txt");
	return 0;
}
