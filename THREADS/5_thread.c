#include<stdio.h>
#include<pthread.h>
void* threadfun(void* arg){
	pthread_t tid=pthread_self();
	printf("%lu\n",(unsigned long )tid);
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
