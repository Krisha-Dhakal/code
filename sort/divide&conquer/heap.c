#include <stdio.h>

int comparisons = 0; // Variable to count comparisons
int swaps = 0;      // Variable to count swaps

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        swaps++; // Increment the swap count

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        swaps++; // Increment the swap count

        heapify(arr, i, 0);
    }
}

int main() {
    int array[50], num, i;

    printf("Enter the size of array: ");
    scanf("%d", &num);

    printf("Enter the elements of array: \n");
    for (i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array before sorting is: \n");
    for (i = 0; i < num; i++) {
        printf("%d\t", array[i]);
    }

    printf("\n");

    heapSort(array, num);

    printf("Array after sorting is: \n");
    for (i = 0; i < num; i++) {
        printf("%d\t", array[i]);
    }

    printf("\n");

    printf("Comparisons: %d\n", comparisons);
    printf("Swaps: %d\n", swaps);

    return 0;
}
