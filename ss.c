#include <stdio.h>

int i, j, n, b[10], w[10], tat[10], t, ct[10], max; 
float at=0, att=0, temp=0;

int main()
{
    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter burst time for process %d:\n",i+1);
        scanf("%d",&b[i]);
        ct[i]=b[i];
    }

    printf("Enter time quantum: ");
    scanf("%d",&t);

    max=b[0];
    for(i=1;i<n;i++)
    {
        if(b[i]>max)
        {
            max=b[i];
        }
    }

    for(j=0;j<(max/t)+1;j++)
    {
        for(i=0;i<n;i++)
        {
            if(b[i] != 0)
            {
                if(b[i] <= t)
                {
                    tat[i] = temp + b[i];
                    temp = temp + b[i];
                    b[i] = 0;
                }
                else
                {
                    b[i] = b[i] - t;
                    temp = temp + t;
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        w[i] = tat[i] - ct[i];
        att += tat[i];
        at += w[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n", i+1, ct[i], w[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", at/n);
    printf("Average Turnaround Time = %.2f\n", att/n);

    return 0;
}
--------------------
#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int s) {
    return s - 1;
}

int signal(int s) {
    return s + 1;
}

void producer() {
    if(mutex == 1 && empty != 0) {
        mutex = wait(mutex);
        x++;
        printf("Producer produces item %d\n", x);
        full = signal(full);
        empty = wait(empty);
        mutex = signal(mutex);
    } else {
        printf("Buffer is full! Cannot produce.\n");
    }
}

void consumer() {
    if(mutex == 1 && full != 0) {
        mutex = wait(mutex);
        printf("Consumer consumes item %d\n", x);
        x--;
        full = wait(full);
        empty = signal(empty);
        mutex = signal(mutex);
    } else {
        printf("Buffer is empty! Cannot consume.\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Producer\n");
        printf("2. Consumer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
================
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int flag[2] = {0, 0};
int turn;

void* process(void* pa) {
    int i = *(int*)pa;
    int other = 1 - i;

    for(int k = 0; k < 5; k++) {
        flag[i] = 1;
        turn = other;
        while(flag[other] == 1 && turn == other)
            ; // busy wait

        printf("Process %d is in critical section\n", i);

        flag[i] = 0; // exit critical section
        usleep(100);
    }
    return NULL;
}

int main() {
    pthread_t t0, t1;
    int id0 = 0, id1 = 1;

    pthread_create(&t0, NULL, process, &id0);
    pthread_create(&t1, NULL, process, &id1);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    return 0;
}
