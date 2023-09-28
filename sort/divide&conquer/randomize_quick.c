#include <stdio.h>
#include <math.h>
int partition(int a[], int p, int r);
int comp = 0; // Initialize comparison counter
int swap = 0;      // Initialize swap counter

int random(int p, int r) {
    int med;
    med = floor((p + r) / 2);
    return med;
}

int randomize_partition(int a[], int p, int r) {
    int temp, k;
    k = random(p, r);

    // Counting a swap
    temp = a[p];
    a[p] = a[k];
    a[k] = temp;
    swap++;

    return partition(a, p, r);
}

int partition(int a[], int p, int r) {
    int pivot, i, j, temp, temp1;
    pivot = a[p];
    i = p;
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
    temp1 = a[p];
    a[p] = a[i];
    a[i] = temp1;
    swap++; // Counting the final swap when the pivot position is found
    return i;
}

void randomize_qs(int a[], int p, int r) {
    int q, i;
    if (p < r) {
        q = randomize_partition(a, p, r);
        randomize_qs(a, p, q - 1);
        randomize_qs(a, q + 1, r);
    }
}

int *return_sorted_array(int a[], int n) {
    randomize_qs(a, 0, n - 1);
    return a;
}

int main() {
    int n, a[50], i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("The array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    int p = a[0];
    int r = a[n - 1]; // Use n-1 as the index for the last element
    int *sorted_array = return_sorted_array(a, n);
    printf("\nThe sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", sorted_array[i]);
    }

    printf("\nThe comparison count is: %d\n", comp);
    printf("The swap count is: %d\n", swap);

    return 0;
}

