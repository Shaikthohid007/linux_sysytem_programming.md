#include<stdio.h>
#include<pthread.h>

void* threadfun(void* arg){
	char *msg=(char*)arg;
	printf("%s\n",msg);
	return NULL;
}

int main(){

	pthread_t t1,t2,t3;
	printf("main start\n");

	pthread_create(&t1,NULL,threadfun,"thohid1");
	pthread_create(&t2,NULL,threadfun,"thohid2");
	pthread_create(&t3,NULL,threadfun,"thohid3");

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	return 0;
}
