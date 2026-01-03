#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;
 void* threadfun(void* arg){
	 int i,count=0;

	 for(i=0;i<5;i++){

		 pthread_mutex_lock(&lock);

		 count++;

		 printf("%ld->%d\n",pthread_self(),count);
		 

		 pthread_mutex_unlock(&lock);
	 }

		 printf("%d\n",count);

		 return NULL;
 }

int main(){

	pthread_t t1,t2;

	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}

