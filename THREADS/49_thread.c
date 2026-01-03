#include<stdio.h>
#include<pthread.h>
#include<string.h>
 void* threadfun(void* arg){
	 char *str=(char*)arg;
	 int i;
	 int n=strlen(str);
	 if(str[n-1]=='\n')
		 n--;

	 for(i=n-1;i>=0;i--){
		 printf("%c",str[i]);
	 }
	 return NULL;
 }
int main(){

	char str[100];
	fgets(str,100,stdin);
	str[strcspn(str,"\n")]='\0';

	pthread_t t1;
	pthread_create(&t1,NULL,threadfun,str);
	pthread_join(t1,NULL);
	return 0;
}
