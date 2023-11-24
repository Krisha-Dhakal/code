#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the Longest Common Subsequence
void findLCS(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];
	int i, j;
    // Build the L table
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    int lcsLength = L[m][n]; // Length of LCS
    char lcs[lcsLength + 1]; // Array to store LCS

    // Backtrack to find LCS
    i = m;
	j = n;
	int index = lcsLength;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    lcs[lcsLength] = '\0'; // Null-terminate the LCS string

    printf("\nLongest Common Subsequence: %s", lcs);
}

int main() {
    char X[100], Y[100]; // Input strings
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X); // Length of the first string
    int n = strlen(Y); // Length of the second string

    findLCS(X, Y, m, n);
	printf("\nName: Krisha Dhakal\tRoll no:8");
    return 0;
}

