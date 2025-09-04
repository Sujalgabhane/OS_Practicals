#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, t = 0, completed = 0, min_index;
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20], finish[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P[%d] (AT BT): ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time initially = burst time
        finish[i] = 0;   // mark unfinished
    }

    while(completed != n) {
        min_index = -1;
        int min_rt = INT_MAX;

        // find process with shortest remaining time at current time
        for(i = 0; i < n; i++) {
            if(at[i] <= t && finish[i] == 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                min_index = i;
            }
        }

        if(min_index == -1) {
            // no process has arrived yet, move time forward
            t++;
            continue;
        }

        // run process for 1 unit
        rt[min_index]--;
        t++;

        // if finished
        if(rt[min_index] == 0) {
            finish[min_index] = 1;
            completed++;
            ct[min_index] = t;
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            avgwt += wt[min_index];
            avgtat += tat[min_index];
        }
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nProcess\tAT\tBT\tWT\tTAT\tCT\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}
