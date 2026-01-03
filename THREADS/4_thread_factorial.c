#include<stdio.h>
#include<pthread.h>
void* threadfun(void* arg){
int n=*(int*)arg;
long  fact=1;

for(int i=1;i<=n;i++){
	fact=fact*i;
}

printf("%d->%ld\n",n,fact);
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

