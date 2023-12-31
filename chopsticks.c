#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

void dine(int n);
pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t
chopstick[NUM_CHOPSTICKS];

int main()
{  //define counter var i and status_message
    int i,status_message;
    void *msg;
    //Initialise the semaphore array
    for(i=0;i<=NUM_CHOPSTICKS;i++)
    {
        status_message=pthread_mutex_init(&chopstick[i],NULL);
        if(status_message==-1)
        {
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }
    for(i=1;i<=NUM_PHILOSOPHERS;i++)
    {
        status_message=pthread_create(&philosopher[i],NULL,(void*)dine,(int*)i);
        if(status_message!=0)
        {
            printf("\n thread creation error \n");
            exit(1);

        }
    }
    //wait for philosophers threads to complete

    for(i=0;i<=NUM_PHILOSOPHERS;i++)
    {
        status_message==pthread_join(philosopher[i],&msg);
        if(status_message!=0)
        {
            printf("\n thread join failed\n");
            exit(1);
        }
    }
    for(i=1;i<=NUM_CHOPSTICKS;i++)
    {
        status_message=pthread_mutex_destroy(&chopstick[i]);
        if(status_message!=0)
        {
            printf("\n mutex destroyed\n");
            exit(1);
        }
    }
    return 0;
}
void dine(int n)
{
    printf("\n philosopher %d is thinking",n);
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n+1)%NUM_CHOPSTICKS]);
    printf("\n philosopher %d is eating",n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
     pthread_mutex_unlock(&chopstick[(n+1)%NUM_CHOPSTICKS]);
     printf("\n philosopher %d finished eating",n);

}
/* philosopher 3 is thinking
 philosopher 3 is earting
 philosopher 2 is thinking
 philosopher 1 is thinking
 philosopher 4 is thinking
 philosopher 5 is thinking
 philosopher 3 finished eationg
 philosopher 2 is earting
 philosopher 4 is earting
 philosopher 4 finished eationg
 philosopher 2 finished eationg
 philosopher 1 is earting
 philosopher 1 finished eationg
 philosopher 5 is earting
 philosopher 5 finished eationg
 */