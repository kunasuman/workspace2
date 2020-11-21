#include<stdio.h>
#include<pthread.h>


#define MAX 1000000

pthread_mutex_t mutex;
int var=0;
void fuctn(int k)
{
	pthread_mutex_lock(&mutex);
	var=var+k;
	pthread_mutex_unlock(&mutex);
}
void *fuctn_add(void *arg)
{
	int i=0;
	while(i<MAX)
	{
		fuctn(1);
		i++;
	}
}
void *fuctn_sub(void *arg)
{
	int i=0;
	while(i<MAX)
	{
		fuctn(-1);
		i++;
	}
}
void main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,fuctn_add,NULL);
	pthread_create(&tid2,NULL,fuctn_sub,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
