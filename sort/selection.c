#include <stdio.h>
void selection_sort(int a[], int n)
{
    int i, j, temp;
	int count = 0; // Initialize comparison count
	int swap = 0;  // Initialize swap count
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            count++; // Increment the comparison count
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swap++; // Increment the swap count
            }
        }
    }
    printf("\nComparison count is: %d\n", count);
    printf("Swap count is: %d\n", swap);
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
    selection_sort(a, n);
    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    
    return 0;
}
