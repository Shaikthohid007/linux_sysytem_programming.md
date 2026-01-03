#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void* threadfun(void* arg){

	pthread_t tid=pthread_self();

     pthread_mutex_lock(&lock);
     printf("%lu\n",(unsigned long)tid);
     pthread_mutex_unlock(&lock);
     return NULL;
}
int main(){
        pthread_t t1,t2;


        pthread_mutex_init(&lock,NULL);

        pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun,NULL);
        pthread_join(t1,NULL);
	pthread_join(t2,NULL);

        pthread_mutex_destroy(&lock);

        return 0;
}

