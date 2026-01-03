#include<stdio.h>
#include<pthread.h>

 pthread_mutex_t lock;

 void* threadfun(void* arg){

	 int *n=(int*)arg;

	 pthread_mutex_lock(&lock);

	 printf("num=%d\n",*n);

	 pthread_mutex_unlock(&lock);

	 return NULL;
 }

int main(){

	pthread_t t1;

	int num;

	scanf("%d",&num);

	pthread_mutex_init(&lock,NULL);

	pthread_create(&t1,NULL,threadfun,&num);

	pthread_join(t1,NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
