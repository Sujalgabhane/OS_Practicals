#include <stdio.h>
int main() {
    int n, m, i, j, k;
    int alloc[10][10], req[10][10], avail[10];
    int finish[10], work[10], deadlock = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < m; i++)
        work[i] = avail[i];
    for (i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (req[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = 1;
                    found = 1;
                    count++;
                    printf("Process P%d executed successfully.\n", i);
                }
            }
        }
        if (!found) {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlock = 1;
            break;
        }
    }

    if (deadlock)
        printf("\nSystem is in DEADLOCK state.\n");
    else
        printf("\nSystem is in SAFE state.\n");

    return 0;
}
