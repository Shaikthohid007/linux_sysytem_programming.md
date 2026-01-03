#include<stdio.h>
#include<pthread.h>

void*sumofsquare(void* arg){

	int i,sum=0;

	for(i=0;i<=100;i++){
		sum+=i*i;
	}

	printf("%d\n",sum);

	return NULL;
}

int main(){

	pthread_t t1;

	pthread_create(&t1,NULL,sumofsquare,NULL);
	pthread_join(t1,NULL);
	return 0;
}
