#include <stdio.h>

void bubble_sort(int a[], int n)
{
    int count = 0, swap = 0;
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            count++; // Increment the comparison count
            if (a[j] > a[j + 1])
            {
                swap++; // Increment the swap count
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\n\nThe comparison count is: %d\n", count);
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

    bubble_sort(a, n);

    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}

