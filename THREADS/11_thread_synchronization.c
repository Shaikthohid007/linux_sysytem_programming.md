#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void* threadfun(void* arg){
	
     pthread_mutex_lock(&lock);
     printf("hello world\n");
     pthread_mutex_unlock(&lock);
     return NULL;
}
int main(){
	pthread_t t1;
	

	pthread_mutex_init(&lock,NULL);

	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_join(t1,NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
