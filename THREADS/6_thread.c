#include<stdio.h>
#include<pthread.h>
 void* threadfun(void* arg){
	 int * num=(int*)arg;
	 int a=num[0];
	 int b=num[1];

	 printf("sum=%d\n",a+b);
	 printf("product=%d\n",a*b);

	 
	 return NULL;
 }

int main(){
	pthread_t t1;

	int num[2];
	scanf("%d%d",&num[0],&num[1]);

	pthread_create(&t1,NULL,threadfun,num);
	pthread_join(t1,NULL);
	return 0;
}
