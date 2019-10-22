#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *stream;
	FILE *wstream;
	char buf[1024];
	memset(buf,'\0',sizeof(buf));
	stream=popen("ls -l","r");
	wstream=fopen("popen.txt","w+");
	fread(buf,sizeof(char),sizeof(buf),stream);
	fwrite(buf,1,sizeof(buf),wstream);
	fclose(stream);
	fclose(wstream);

	return 0;
}
