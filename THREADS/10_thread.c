#include<stdio.h>
#include<pthread.h>
#include<string.h>
void* threadfun(void* arg){
	char *str=(char*)arg;

	int start=0;
	int end= strlen(str)-1;
	while(start<end){

	if(str[start]!=str[end]){
		printf("not palindrom\n");
		return NULL;
	}
	start++;
	end--;
	}
	printf("palindrom\n");
	return NULL;
}

int main(){
	char str[100];
	scanf("%s",str);

	pthread_t t1;
	pthread_create(&t1,NULL,threadfun,str);
	pthread_join(t1,NULL);
	 return 0;
}
