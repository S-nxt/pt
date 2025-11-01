#include <stdio.h>
#include <unistd.h>   
#include <stdlib.h>   

int main() {
    printf("Before fork: Parent process ID = %d\n", getpid());

    int pid = fork();  // create a new process

    if (pid < 0) {
        printf("error during fork");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID (of child): %d\n", getppid());
        exit(0);
    } 
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (from fork): %d\n", pid);
        printf("Parent process id(from parent) is: %d\n", getppid());
        exit(0);
    }

    return 0;
}
-------------------------------------------
#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10];
    int i, j, n, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    // Sort processes according to arrival time
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(at[j] > at[j+1]) {
                // Swap arrival time
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // Swap process ID
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    // Calculate completion time
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        if(at[i] > ct[i-1])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Calculate turnaround time and waiting time
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    atat /= n;
    awt /= n;

    printf("\nAverage Turnaround Time = %.2f\n", atat);
    printf("Average Waiting Time = %.2f\n", awt);

    return 0;
}
OR
#include <stdio.h>

int main() {
    int p[10], bt[10], ct[10], tat[10], wt[10];
    int n, i;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for each process:\n");
    for(i = 0; i < n; i++) {
        p[i] = i + 1;  // Process IDs: P1, P2, ...
        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for(i = 1; i < n; i++)
        ct[i] = ct[i-1] + bt[i];

    // Calculate Turnaround Time and Waiting Time
    printf("\nProcess\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];          // Since AT=0 → TAT = CT - AT = CT
        wt[i] = tat[i] - bt[i];  // WT = TAT - BT
        atat += tat[i];
        awt += wt[i];
        printf("P%d\t%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Averages
    atat /= n;
    awt /= n;

    printf("\nAverage Turnaround Time = %.2f\n", atat);
    printf("Average Waiting Time = %.2f\n", awt);

    return 0;
}
----------------fcfs
#include<stdio.h>

int main()
{
	int bt[20], wt[20],tat[20],i,n;
	float wtavg,tatavg;

	printf("\nEnter the number of processes --");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Burst Time for Process %d --",i);
		scanf("%d",&bt[i]);
	}
	wt[0] =wtavg=0;
	tat[0]=tatavg = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg +tat[i];
	}
	printf("\t PROCESS \t BURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++)
		printf("\n\t P%d \t\t %d \t\t %d \t\t %d",i,bt[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time.--%f",wtavg/n);
	printf("\nAverage Turnaround Time.--%f",tatavg/n);
	return 0;
}
