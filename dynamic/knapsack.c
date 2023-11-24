#include <stdio.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem using dynamic programming
int knapsack(int profits[], int weights[], int n, int capacity) {
    int c[n + 1][capacity + 1];
	int i, w;
    // Build the c table
    for (i = 0; i <= n; i++) {
        for ( w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                c[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                c[i][w] = max(profits[i - 1] + c[i - 1][w - weights[i - 1]], c[i - 1][w]);
            } else {
                c[i][w] = c[i - 1][w];
            }
        }
    }

    // The result is in c[n][capacity]
    return c[n][capacity];
}

int main() {
    int n, i; // Number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profits[n], weights[n]; // Arrays to store profits and weights of items

    // Input item profits and weights
    printf("Enter the profits of items:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter the weights of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int capacity; // Knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(profits, weights, n, capacity);
    printf("Maximum profit in the knapsack = %d\n", maxValue);
	printf("\nName: Krisha Dhakal\tRoll No: 8");
    return 0;
}

