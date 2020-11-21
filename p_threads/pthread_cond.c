#include<stdio.h>
#include<pthread.h>

pthreasd_cond_t cond =PTHREAd_COND_INITIALI;
pthread_multex_t multex =PTHREAD_MULTEX-INITIALI;

void fuctn()
{
	int i=65;
	while(i<)
	{
		printf("%c",i);
		i++;
	}
	printf("\n");
}

void *fuctn1(void *arg)
{
	pthread_multex_lock(&multex);
	pthread_cond_wait(&cond,&multex);
	fuctn();
	pthread_multex_unlock(&multex);
	printf("%s : thread Running \n",__fuctn__);
	printf("I'M about exit \n");
}

void *fuctn2(void *arg)
{
	printf("%s : thread Running\n",__fuctn__);
	fuctn();
	pthread_cond_signal(&cond);
}

void main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,&fuctn1,NULL);
	pthread_create(&tid2,NULL,&fuctn2,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid1,NULL);

}
