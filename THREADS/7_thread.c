#include<stdio.h>
#include<pthread.h>
void* threadfun(void* arg){
	int n=*(int *)arg;

	int square=n*n;

	printf("%d-%d\n",n,square);
	return NULL;
}

int main(){
	pthread_t t1;

	int num;
	scanf("%d",&num);

	pthread_create(&t1,NULL,threadfun,&num);
	pthread_join(t1,NULL);
	return 0;
}
