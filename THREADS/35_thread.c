#include<stdio.h>
#include<pthread.h>

void* threadfun(void* arg){
	int rem,digit=0;
	int *n=(int*)arg;

	while(*n>0){
		rem=*n%10;
		digit=digit+rem;
		*n=*n/10;
	}
	printf("%d\n",digit);

	return NULL;
}

int main(){
	int num;
	scanf("%d",&num);

	pthread_t t1;

	pthread_create(&t1,NULL,threadfun,&num);
	pthread_join(t1,NULL);
	return 0;
}

