#include<stdio.h>
#include<pthread.h>

void*threadfun(void* arg){
	int *arr=(int*)arg;
	int i;
	int max=arr[0];

	for(i=1;i<5;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("%d\n",max);

	return NULL;
}
int main(){
	int arr[10];
	int i;
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}

	pthread_t t1;

	pthread_create(&t1,NULL,threadfun,arr);
	pthread_join(t1,NULL);

	return 0;
}
