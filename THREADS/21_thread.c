#include<stdio.h>
#include<pthread.h>
 void* threadfun(void* arg){

	 int *arr=(int*)arg;
	 int i,j,temp;

	 for(i=0;i<5;i++){
		 
		 for(j=i+1;j<5;j++){
			 if(arr[i]>arr[j]){

	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;
	 
	 }
		 }
	 }

	 

	 for(i=0;i<5;i++){
		 printf("%d\n",arr[i]);
	 }
	 return NULL;
 }

int main(){

	pthread_t t1;
	int i;

	int arr[10];

	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}

	pthread_create(&t1,NULL,threadfun,arr);
	pthread_join(t1,NULL);

	return 0;
}

