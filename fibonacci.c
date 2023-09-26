#include <stdio.h>
int main() 
{
	int times;
  int i, n;
  int prev = 0, curr = 1;
  int next = prev + curr;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("Fibonacci Series: %d\t%d\t ", prev, curr);
  for (i = 3; i <= n; ++i) 
  {
    printf("%d\t ", next);
    prev = curr;
    curr = next;
    next = prev + curr;
    times++;
  }
	printf("\nNo. of times for loop executed is: %d",times);
  return 0;
}