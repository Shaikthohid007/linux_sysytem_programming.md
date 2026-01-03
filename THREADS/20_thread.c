#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX 100

int dp[MAX][MAX];
pthread_mutex_t lock;

void* checkPalindrome(void* arg)
{
    char *str = (char*)arg;
    int n = strlen(str);
    int i, j, len;

    pthread_mutex_lock(&lock);

    // Single characters
    for (i = 0; i < n; i++)
        dp[i][i] = 1;

    // Substrings of length >= 2
    for (len = 2; len <= n; len++)
    {
        for (i = 0; i <= n - len; i++)
        {
            j = i + len - 1;

            if (str[i] == str[j])
            {
                if (len == 2)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            else
                dp[i][j] = 0;
        }
    }

    if (dp[0][n - 1])
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t t1;
    char str[MAX];

    scanf("%s", str);

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, checkPalindrome, str);
    pthread_join(t1, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

