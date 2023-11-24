#include<stdio.h>
#include<math.h>

void printboard(int n);
void fourQueen(int k,int n);
int place(int k,int i);
int x[100];

void NQueen(int k,int n)
{
  int i;
  for(i=1;i<=n;i++)
  {
    if(place(k,i)==1)
    {     x[k]=i;
            if(k==n)
            {
                printf("\nSolution\n");
                printboard(n);
            }
            else
                NQueen(k+1,n);
    }
  }
}

int place(int k,int i)
{
  int j;
  for(j=1;j<k;j++)
  {
    if((x[j]==i)||abs(x[j]-i)==abs(j-k))
        return 0;
  }
  return 1;
}

void printboard(int n)
{
  int i;
  for(i=1;i<=n;i++)
    printf("%d  ",x[i]);
}

void main()
{
    int n;
    printf("Enter Value of N:");
    scanf("%d",&n);
    NQueen(1,n);
}