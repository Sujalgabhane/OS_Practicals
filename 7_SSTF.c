#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i, j;
    printf("Enter Number Of Indexes: ");
    scanf("%d", &n);

    int arr[n];
    int head;
    int seek_count = 0;
    int distance, min_distance, index;
    int completed[n]; 

    printf("Enter The Indexes Of Requested Array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        completed[i] = 0; 
    }

    printf("Enter Head: ");
    scanf("%d", &head);

    printf("\nSeek Sequence:\n");

    for (i = 0; i < n; i++) {
        min_distance = 100000; 
        index = -1;

        for (j = 0; j < n; j++) {
            if (!completed[j]) {
                distance = abs(head - arr[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    index = j;
                }
            }
        }
        
        seek_count += min_distance;
        head = arr[index];
        completed[index] = 1;

        printf("%d ", head);
    }

    printf("\nTotal number of seek operations: %d\n", seek_count);

    return 0;
}
