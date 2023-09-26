#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int i, j, temp;
    int comp = 0, swap = 0; // Initialize counts

    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;

        while (temp < a[j] && j >= 0)
        {
            comp++; // Increment the comparison count
            a[j + 1] = a[j];
            j = j - 1;
            swap++; // Increment the swap count
        }

        a[j + 1] = temp;
    } 

    printf("\nThe comparison count is: %d\n", comp);
    printf("The swap count is: %d\n", swap);
}

int main()
{
    int a[50], n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter %d elements in an array: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nBefore Sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    insertion_sort(a, n);
    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
