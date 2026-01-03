#include<stdio.h>
#include<pthread.h>
 void* threadfun(void* arg){
	 int *arr=(int*)arg;
	 int i;
	 int found=0;
	 int key=arr[5];

	 for(i=0;i<5;i++){
		 if(arr[i]==key){
			 printf("%d->%d\n",i,key);
			 found=1;
			 break;
		 }
	 }
	 if(!found)
	 printf("not found%d\n",key);
 
	 return NULL;
 }

int main(){

	int i;
	int arr[10];
	int key;

	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
	}

	scanf("%d",&arr[5]);
	pthread_t t1;

	pthread_create(&t1,NULL,threadfun,arr);
	pthread_join(t1,NULL);

	return 0;
}

			

