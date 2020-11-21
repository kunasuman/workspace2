#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#define stacksixe(1024*1024)

int child_proc(void *args)
{
	int i=0,pid;
	pid = getpid();
	printf("%s : PID is %d\n"__fucn__,pid);
	while(i<5)
	{
		printf("hello \n");
		sleep(1);
		i++;
	}
}
void main()
{
	int pid;
	char *stack_head;
	char *s;
	s=malloc(Stack_sixe);
	stack_head = s+stacksixe;
	clone(child_proc,stack_head,SIGCHLD,NULL);
	pid=getpid();
	 printf("%s : PID is %d\n"__fucn__,pid);
}
