#include <stdio.h>

// Function to calculate the modular inverse using extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    // Apply extended Euclidean Algorithm
    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Ensure x1 is positive
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

// Function to find the solution using the Chinese Remainder Theorem
int chineseRemainderTheorem(int numEquations, int a[], int m[]) {
    // Calculate the product of all moduli
    int i;
    int M = 1;
    for (i = 0; i < numEquations; i++) {
        M *= m[i];
    }

    int result = 0;

    // Calculate the CRT formula for each equation
    for (i = 0; i < numEquations; i++) {
        int Mi = M / m[i];
        int MiInverse = modInverse(Mi, m[i]);

        result += (a[i] * Mi * MiInverse) % M;
        result %= M;
    }

    return result;
}

int main() {
    int i, numEquations;

    // Get the number of equations from the user
    printf("Enter the number of equations: ");
    scanf("%d", &numEquations);

    int a[numEquations]; // remainders
    int m[numEquations]; // moduli

    // Get input for each equation
    for (i = 0; i < numEquations; i++) {
        printf("Equation %d: remainder (a) and modulus (m): ", i + 1);
        scanf("%d %d", &a[i], &m[i]);
    }

    // Use the Chinese Remainder Theorem to find the solution
    int result = chineseRemainderTheorem(numEquations, a, m);

    printf("Solution = x: %d\n", result);
    printf("Name: Krisha Dhakal\tRoll: 8");
    return 0;
}
