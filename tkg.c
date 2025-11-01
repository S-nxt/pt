#include <stdio.h>

int main() {
    int n, bt[10], p[10], ct[10], tat[10], wt[10];
    int i, j, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by burst time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Completion Time
    ct[0] = bt[0];
    for (i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    // Turnaround and Waiting Times
    printf("\nProcess\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("P%d\t%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", atat / n);
    printf("Average Waiting Time = %.2f\n", awt / n);

    return 0;
}
---------------priority
#include <stdio.h>

int main() {
    int n, bt[10], p[10], pr[10], ct[10], tat[10], wt[10];
    int i, j, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    printf("Enter priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++) {
        printf("Priority for P%d: ", p[i]);
        scanf("%d", &pr[i]);
    }

    // Sort by priority (ascending)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1]) {
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Completion Time
    ct[0] = bt[0];
    for (i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    // Turnaround and Waiting Times
    printf("\nProcess\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
        printf("P%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", atat / n);
    printf("Average Waiting Time = %.2f\n", awt / n);

    return 0;
}
