#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock;

void* fibsum(void* arg){

	int n=*(int*)arg;
	int *fib;
	int i;
	long sum=0;

	fib=(int*) malloc((n+1) * sizeof(int));

	if(fib==NULL){
		printf("error\n");
		 return NULL;
	}

	fib[0]=0;
	if(n>=1)
		fib[1]=1;

	for(i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}

	for(i=0;i<=n;i++){
		sum=sum+fib[i];
	}

	pthread_mutex_lock(&lock);

	printf("%d->%ld\n",n,sum);

	pthread_mutex_unlock(&lock);

	free(fib);

	return NULL;

}

int main() {

	pthread_t t1;

	int limit;

	scanf("%d",&limit);

	pthread_mutex_init(&lock,NULL);

	pthread_create(&t1,NULL,fibsum,&limit);

	pthread_join(t1,NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
