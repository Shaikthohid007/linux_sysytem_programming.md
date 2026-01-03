#include<stdio.h>
#include<pthread.h>
 void* threadfun(void* arg){
	 printf("%s\n",(char*)arg);
 return NULL;
 }

 int main(){
	 pthread_t t1;
	 pthread_create(&t1,NULL,threadfun,"hello");
	 pthread_join(t1,NULL);
 }
