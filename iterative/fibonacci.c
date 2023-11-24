#include <stdio.h>
int fibo(int n)
{
  int times, i;
  int prev = 0, curr = 1;
  int next = prev + curr;
  printf("Fibonacci Series: %d\t%d\t ", prev, curr);
  for (i = 3; i <= n; ++i) 
  {
    printf("%d\t ", next);
    prev = curr;
    curr = next;
    next = prev + curr;
    times++;
  }
  printf("\nNo. of times for loop executed is: %d\n",times);
  printf("Name: Krisha Dhakal\tRoll No: 8");
}
int main() 
{
	int n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  fibo(n);
  return 0;
}