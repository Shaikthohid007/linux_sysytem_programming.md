#include<stdio.h>
#include<pthread.h>
void* threadfun(void* arg){
	int *n=(int*)arg;
	int i;
	int flag=0;

	for(i=1;i*i<=*n;i++){
		if(i*i==*n){
			flag=1;
			break;
		}
	}

	if(flag)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}

int main(){

	int num;

	scanf("%d",&num);

	pthread_t t1;

	pthread_create(&t1,NULL,threadfun,&num);
	pthread_join(t1,NULL);
	return 0;
}
