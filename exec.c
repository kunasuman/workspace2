#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main()
{
	if (fork())
	{
		printf("am parent(pid = %d\n",getpid());

	}
	else
	{
		execv("./play/game",NULL);
	}
	printf("bye");
}
