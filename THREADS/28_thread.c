#include<stdio.h>
#include<pthread.h>

void* threadfun(void* arg){

	int i,sum=0;

	for(i=0;i<=100;i++){
		if(i%2==0){
			sum+=i;
		}
	}

	printf("%d\n",sum);

	return NULL;
}

int main(){

	pthread_t t1;

	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_join(t1,NULL);

	return 0;
}
