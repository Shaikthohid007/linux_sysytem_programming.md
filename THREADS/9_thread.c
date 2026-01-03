#include<stdio.h>
#include<pthread.h>
void* threadfun(void* arg){
	int n=*(int*)arg;
	int count=0;

	if(n<=0){
		printf("number is invalid\n");
		return 0;
	}

	int i;
	for(i=1;i<=n;i++){
		if(n%i==0)
			count++;
	}
	if(count==2)
		printf("prime\n");
	else
		printf("not\n");

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
