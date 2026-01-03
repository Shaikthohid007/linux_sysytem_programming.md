#include<stdio.h>
#include<pthread.h>
#include<string.h>
 void* stringfun(void* arg){
	  char *str=(char*)arg;

	  for(int i=0;str[i]!='\0';i++){
		  printf("%c",str[i]);
	  }

	  return NULL;
 }
int main(){

	char str[100];
	fgets(str,100,stdin);

	pthread_t t1;

	pthread_create(&t1,NULL,stringfun,str);
	pthread_join(t1,NULL);
	return 0;
}
