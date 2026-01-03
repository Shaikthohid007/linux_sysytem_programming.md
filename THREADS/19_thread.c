#include <stdio.h>
#include <pthread.h>

#define MAX_YEAR 3000

int dp[MAX_YEAR];        // DP table
pthread_mutex_t lock;

void* checkLeap(void* arg)
{
    int year = *(int*)arg;

    pthread_mutex_lock(&lock);

    // Already calculated?
    if (dp[year] != -1)
    {
        if (dp[year] == 1)
            printf("%d is a Leap Year (from DP)\n", year);
        else
            printf("%d is NOT a Leap Year (from DP)\n", year);

        pthread_mutex_unlock(&lock);
        return NULL;
    }

    // Calculate leap year
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        dp[year] = 1;
        printf("%d is a Leap Year\n", year);
    }
    else
    {
        dp[year] = 0;
        printf("%d is NOT a Leap Year\n", year);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1;
    int year, i;

    // Initialize DP table
    for (i = 0; i < MAX_YEAR; i++)
        dp[i] = -1;

    scanf("%d", &year);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, checkLeap, &year);
    pthread_join(t1, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}


