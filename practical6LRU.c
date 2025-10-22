#include <stdio.h>

int main() {
    int pages[30], frames[10], counter[10];
    int n, f, i, j, k, pageFaults = 0, time = 0, flag, least;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        counter[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        flag = 0;

        // Check if page already in frames
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                time++;
                counter[j] = time; // update usage time
                flag = 1;
                break;
            }
        }

        // If page not found -> replace LRU page
        if (flag == 0) {
            int pos = -1;
            // Find empty frame
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                // Find least recently used page
                least = 0;
                for (j = 1; j < f; j++) {
                    if (counter[j] < counter[least])
                        least = j;
                }
                pos = least;
            }

            time++;
            frames[pos] = pages[i];
            counter[pos] = time;
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
