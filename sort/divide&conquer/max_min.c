#include <stdio.h>
#include <math.h>
void max_min(int a[], int l, int r, int *max, int *min) {
    if (l == r) {
        *max = *min = a[l];
    } else if (l == r - 1) {
        if (a[l] > a[r]) {
            *max = a[l];
            *min = a[r];
        } else {
            *max = a[r];
            *min = a[l];
        }
    } else {
        int mid = (l + r) / 2;
        int max1, max2, min1, min2;
        max_min(a, l, mid, &max1, &min1);
        max_min(a, mid + 1, r, &max2, &min2);

        if (max1 > max2) {
            *max = max1;
        } else {
            *max = max2;
        }

        if (min1 < min2) {
            *min = min1;
        } else {
            *min = min2;
        }
    }
}

int main() {
    int a[50], i, n, max, min;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements in array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max_min(a, 0, n - 1, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d", min);

    return 0;
}
