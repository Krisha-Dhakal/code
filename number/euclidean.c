#include <stdio.h>
// Function to find the GCD using Euclid's algorithm
int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int num1, num2;
    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    // Find and display the GCD
    int gcd = euclideanGCD(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);
    printf("Name: Krisha Dhakal\tRoll: 8");
    return 0;
}
