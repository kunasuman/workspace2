#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void parent_proc();
void child_proc();

int fd[2];

void main()
{
	pipe(fd);
	if (fork())
	{
		parent_proc();
	}
	else
	{
		child_proc();
	}
}
void parent_proc()
{
	char pbuff[20]="ipl over";
	printf("parent process (PID=%d)\n",getpid());
	write(fd[1],pbuff,sieof(pubff));
}
void child_proc()
{
	char cbuff[20]="\0";
	printf("child proceass (PID=%d)\n",getpid());
	read(fd[0],cbuff,sieof(cbuff));
	printf("data recived is %s\n",cbuff);
}
