#include<stdio.h>
#include<pthread.h>
 int result;

 pthread_mutex_t lock;

 void* threadfun(void* arg){
	 int *num=(int*)arg;

	 pthread_mutex_lock(&lock);

	 result=num[0]+num[1];
	 printf("%d\n",result);

	 pthread_mutex_unlock(&lock);

	 return NULL;
 }

int main(){

	pthread_t t1;

	int num[2];

	scanf("%d%d",&num[0],&num[1]);

	pthread_mutex_init(&lock,NULL);

	pthread_create(&t1,NULL,threadfun,num);

	pthread_join(t1,NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}

