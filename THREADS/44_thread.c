#include <stdio.h>
#include <pthread.h>

void* factorials(void* arg)
{
    int i, j;
    long fact;

    for(i = 1; i <= 10; i++)
    {
        fact = 1;
        for(j = 1; j <= i; j++)
        {
            fact *= j;
        }
        printf("%d! = %ld\n", i, fact);
    }

    return NULL;
}

int main()
{
    pthread_t t1;

    pthread_create(&t1, NULL, factorials, NULL);
    pthread_join(t1, NULL);

    return 0;
}

