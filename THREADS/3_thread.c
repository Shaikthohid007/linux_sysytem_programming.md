#include<stdio.h>
#include<pthread.h>
 void* threadfun(void* arg){
	 int i;

	 char *name=(char*)arg;
	 for(i=0;i<10;i++){
	 printf("%s%d\n",name,i);
	 }
	 return NULL;
 }

int main(){
	pthread_t t1,t2;

	pthread_create(&t1,NULL,threadfun,"thread1");
	pthread_create(&t2,NULL,threadfun,"thread2");

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}
