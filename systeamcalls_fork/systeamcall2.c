#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void main()
{
	int i=0;
	int retval;
	retval = fork();

	if( retval !=0)
	{
		printf("am parent %d retval %d\n",getpid(),retval);
			sleep(10);
			wait(NULL);
	}
	else
	{
		printf("am child %d retval %d\n",getpid(),retval);
		while(i<20)
		{
			printf("child HELLO\n");
			sleep(1);
			i++;
		}
	}
}
