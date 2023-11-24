#include <stdio.h>

// Function to check if there exists a subset with the given sum
int isSubsetSum(int set[], int n, int sum) {
    // Base cases
    if (sum == 0) {
        return 1; // Subset with sum 0 is always possible
    }
    if (n == 0 && sum != 0) {
        return 0; // No subset is possible
    }

    // If the last element is greater than the sum, then ignore it
    if (set[n - 1] > sum) {
        return isSubsetSum(set, n - 1, sum);
    }

    // Check if either including or excluding the last element leads to a subset with the given sum
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main() {
    int n;

    // Get the size of the set from the user
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n], i;

    // Get the elements of the set from the user
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int sum;

    // Get the target sum from the user
    printf("Enter the target sum: ");
    scanf("%d", &sum);

    if (isSubsetSum(set, n, sum)) {
        printf("Subset with sum %d exists.\n", sum);
    } else {
        printf("No subset with sum %d exists.\n", sum);
    }
    printf("\nName: Krisha Dhakal\tRoll: 8");
    return 0;
}
