#include <stdio.h>
int times=0;
int factorial(int n)
{
    int i, fact=1;
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
        times++;
    }
    return fact;
}
int main()
{
    int n, f;
    printf("Enter a number: ");
    scanf("%d",&n);
    f=factorial(n);
    printf("The factorial of %d is: %d\n", n, f);
    printf("No. of times for loop executed is: %d\n",times);
}