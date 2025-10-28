#include <stdio.h>
#include <math.h>
int main() {
 int n, i;
 printf("Enter Number Of Indexes: ");
 scanf("%d", &n);
 int arr[n];
 int head;
 int seek_count = 0, cur_track, distance;
 printf("Enter The Indexes Of Requested Array:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("Enter Head: ");
 scanf("%d", &head);
 for (i = 0; i < n; i++) {
 cur_track = arr[i];
 distance = fabs(head - cur_track);
 seek_count += distance;
 head = cur_track;
 }
 printf("Total number of seek operations: %d\n", seek_count);
 return 0;
}