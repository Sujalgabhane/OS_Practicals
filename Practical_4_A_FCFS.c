#include <stdio.h>
int main()
{
    int n;

    printf("Enter Number Of Processes: ");
    scanf("%d", &n);

    int bursttime[n];
    int waitingtime[n];
    int turnaroundtime[n];

    printf("Enter Burst Time of Each Process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        scanf("%d", &bursttime[i]);
    }

    // Calculate waiting time
    waitingtime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitingtime[i] = bursttime[i - 1] + waitingtime[i - 1];
    }

    // Display waiting times
    printf("\nWaiting Time of Each Process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d = %d\n", i, waitingtime[i]);
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
    {
        turnaroundtime[i] = bursttime[i] + waitingtime[i];
    }

    // Display turnaround times
    printf("\nTurnaround Time of Each Process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d = %d\n", i, turnaroundtime[i]);
    }

    // Average waiting time
    int totalwai = 0;
    for (int i = 0; i < n; i++)
    {
        totalwai += waitingtime[i];
    }
    float avgwai = (float)totalwai / n;

    // Average turnaround time
    int totalta = 0;
    for (int i = 0; i < n; i++)
    {
        totalta += turnaroundtime[i];
    }
    float avgta = (float)totalta / n;

    printf("\nAverage Waiting Time = %.2f\n", avgwai);
    printf("Average Turnaround Time = %.2f\n", avgta);

    return 0;
}
