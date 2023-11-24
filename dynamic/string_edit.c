#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int editDistance(char str1[], char str2[], int len1, int len2, char changes[][3], char editedStr[]) {
    int dp[len1 + 1][len2 + 1];
    int i, j;

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find changes
    i = len1;
    j = len2;
    int k, changeCount = 0;
    while (i > 0 && j > 0) {
        if (str1[i - 1] != str2[j - 1]) {
            changes[changeCount][0] = str1[i - 1];
            changes[changeCount][1] = str2[j - 1];
            changes[changeCount][2] = i; // Position in str1
            changeCount++;
        }
        if (dp[i - 1][j - 1] <= dp[i][j - 1] && dp[i - 1][j - 1] <= dp[i - 1][j]) {
            i--;
            j--;
        } else if (dp[i][j - 1] <= dp[i - 1][j] && dp[i][j - 1] <= dp[i - 1][j - 1]) {
            j--;
        } else {
            i--;
        }
    }

    // Apply changes to the original string
    strcpy(editedStr, str1);
    for (k = changeCount - 1; k >= 0; k--) {
        int position = changes[k][2] - 1;
        editedStr[position] = changes[k][1];
    }

    return dp[len1][len2];
}

int main() {
    char str1[100], str2[100];
    char changes[100][3];
    char editedStr[100];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int result = editDistance(str1, str2, len1, len2, changes, editedStr);

    printf("Minimum operations required to convert \"%s\" to \"%s\" is %d\n", str1, str2, result);
    printf("Edited String: %s\n", editedStr);

    printf("Replaced Characters:\n");
    for (int k = 0; k < result; k++) {
        printf("Replace '%c' at position %d with '%c'\n", changes[k][0], changes[k][2], changes[k][1]);
    }

    return 0;
}
