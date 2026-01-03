#include<stdio.h>
#include<pthread.h>
#include<string.h>


void*stringfun( void* arg){
	char *str=(char*)arg;
	int count=0;
	int i;

	for(i=0;str[i]!='\0';i++){
		count++;
	}
	printf("%d\n",count);

	return NULL;
}
int main(){
	char str[100];
	fgets(str,100,stdin);
	str[strcspn(str,"\n")]='\0';

	pthread_t t1;

	pthread_create(&t1,NULL,stringfun,str);
	pthread_join(t1,NULL);
	return 0;
}
