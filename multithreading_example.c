#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *computation()
{
    int i;
    for(i = 0;i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    pthread_t th[10];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for(i = 0; i < 4; i++)
    {
        if(pthread_create(&th[i], NULL, &computation, NULL) != 0)
        {
            perror("Failed to create thread\n");
            return 1;
        }
        if(pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread\n");
            return 2;
        }
    }

    return 0;
}