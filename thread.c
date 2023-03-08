#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include <unistd.h>
pthread_mutex_t lock;
void* function2()
{
//	sleep(2);
//	int var=pthread_mutex_lock(&lock);
	printf("thread 2 was created\n");
	pthread_mutex_unlock(&lock);
}
void* function1()
{
//	int var=pthread_mutex_lock(&lock);
	printf("thread 1 was created\n");
	
	// pthread_mutex_unlock(&lock);
}
void main()
{
	pthread_t p1;
	pthread_t p2;
	pthread_create(&p1,NULL,&function1,NULL);
	pthread_create(&p2,NULL,&function2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}
