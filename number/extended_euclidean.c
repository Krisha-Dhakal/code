#include <stdio.h>

void extended_euclidean_algorithm(int a, int b, int* x, int* y, int* gcd) {
        if (b == 0) {
                *x = 1;
                *y = 0;
                *gcd = a;
        } else {
                int x1, y1;
                extended_euclidean_algorithm(b, a % b, &x1, &y1, gcd);
                *x = y1;
                *y = x1 - (a / b) * y1;
        }
}

int main() {
        int i, a, b, x, y, gcd;
        for(i=0;i<2;i++){
                printf("\nEnter two numbers: ");
                scanf("%d %d", &a, &b);
                extended_euclidean_algorithm(a, b, &x, &y, &gcd);
                printf("The extended Euclidean algorithm for %d and %d is:\n", a, b);
                printf("x = %d, y = %d, gcd = %d\n", x, y, gcd);
        }
        printf("\nName: Krisha Dhakal\tRoll no: 8");
        return 0;
}
