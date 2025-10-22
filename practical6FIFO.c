#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int n, f, i, j, k, pageFaults = 0, next = 0, flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already in frame
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found -> replace using FIFO
        if (flag == 0) {
            frames[next] = pages[i];
            next = (next + 1) % f;
            pageFaults++;
        }

        // Display current frame status
        printf("%d\t", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
