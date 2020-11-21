#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	int retval;
	retval= fork();

	if(retval !=0)
	{
		printf("am parent %d\n",getpid());
		getpid();
	}
	else
	{
		printf("am child %d\n",getpid());
		getpid();
	}
}
