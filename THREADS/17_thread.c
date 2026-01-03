#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;

void* primefunction(void* arg){
	
	int i,j,count;
	int *limit=(int*)arg;

	pthread_mutex_lock(&lock);

	for(i=2;i<=*limit;i++){
		count=0;

	for(j=1;j<=i;j++){

			if(i%j==0)
				count++;
		}
	

	if(count==2)
		printf("%d\n",i);
	}
	return NULL;
}

int main(){

	pthread_t t1;
	int limit;

	scanf("%d",&limit);

	pthread_mutex_init(&lock,NULL);

	pthread_create(&t1,NULL,primefunction,&limit);

	pthread_join(t1,NULL);

	pthread_mutex_destroy(&lock);
	return 0;
}
