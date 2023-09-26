#include <stdio.h>
int comp=0;
int swap=0;
void merge(int a[], int l, int q, int r) {
    int i, x, y, k, b[50];
    x = l;
    y = q + 1;
    k = l;
    
    while (x <= q && y <= r) {
        comp++;
        if (a[x] <= a[y]) {
            b[k] = a[x];
            k++;
            x++;
            swap++;
        } else {
            b[k] = a[y];
            k++;
            y++;
            swap++;
        }
    }

    while (x <= q) {
        
        b[k] = a[x];
        k++;
        x++;
    }

    while (y <= r) {
        b[k] = a[y];
        k++;
        y++;
    }

    for (i = l; i <= r; i++) {
        a[i] = b[i];
    }
}

void merge_sort(int a[], int l, int r) {
    int q;
    if (l < r) {
        q = (l + r) / 2;
        merge_sort(a, l, q);
        merge_sort(a, q + 1, r);
        merge(a, l, q, r);
    }
}

int main() {
    int a[50], num, i;

    printf("Enter the size of array: ");
    scanf("%d", &num);

    printf("Enter the elements of array: \n");
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    printf("Array before sorting is: \n");
    for (i = 0; i < num; i++) {
        printf("%d\t", a[i]);
    }

    printf("\n");

    merge_sort(a, 0, num - 1);

    printf("Array after sorting is: \n");
    for (i = 0; i < num; i++) {
        printf("%d\t", a[i]);
    }

    printf("\n");
    printf("\nThe comparison count is: %d\n", comp);
    printf("The swap count is: %d\n", swap);
    return 0;
}
