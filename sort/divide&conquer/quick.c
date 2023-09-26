#include <stdio.h>

int comp = 0; // Initialize comparison counter
int swap = 0;      // Initialize swap counter

int partition(int a[], int l, int r) {
    int pivot, i, j, temp;
    pivot = a[l];
    i = l;
    for (j = i + 1; j <= r; j++) {
        comp++; // Counting a comparison
        if (a[j] <= pivot) {
            i = i + 1;

            // Counting a swap
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            swap++;
        }
    }
    temp = a[l];
    a[l] = a[i];
    a[i] = temp;
    swap++; // Counting the final swap when the pivot position is found
    return i;
}

void quick_sort(int a[], int l, int r) {
    int q;
    if (l < r) {
        q = partition(a, l, r);
        quick_sort(a, l, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int main() {
    int a[50], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quick_sort(a, 0, n - 1);

    printf("\nThe sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    printf("\nThe comparison count is: %d\n", comp);
    printf("The swap count is: %d\n", swap);

    return 0;
}
