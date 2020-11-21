#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *fuctn1(void *arg)
{
	while(1)
	{
	//	printf("hii (arg=%d)\n",*(int*)arg);
		printf("hii\n");
		sleep(1);
	}
}

void *fuctn2(void *arg)
{
	while(1)
	{
	//	printf("how are you (arg=%d)\n",*(int*)arg);
		printf("how are you\n");
		sleep(2);
	}
}

void *fuctn3(void *arg)
{
	while(1)
	{
	//	printf("dnt talk(arg=%d)\n",*(int*)arg);
		printf("dont talk\n");
		sleep(3);
	}
}

void main()
{
	pthread_t tid1,tid2,tid3;
	pthread_create(&tid1,NULL,fuctn1,NULL);
	pthread_create(&tid2,NULL,fuctn2,NULL);
	pthread_create(&tid3,NULL,fuctn3,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
}
