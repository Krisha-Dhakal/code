#include <stdio.h>
#include <conio.h>
#include <math.h>
int binary_search(int a[], int l, int r, int key)
{
	int mid;
	if(l>r)
	{
		printf("Search unsuccessful.");
		return -1;
	}
	mid=(l+r)/2;
	if(key>a[mid])
	{
		binary_search(a,mid+1,r,key);
	}
	else if(key<a[mid])
	{
		binary_search(a, l, mid-1, key);
	}
	else
	{
		printf("\nSearch Successful.");
		return mid+1;
	}
}
int main()
{
	int a[50], n, i, l, r, key, loc;
	printf("Enter value of n: ");
	scanf("%d",&n);
	l=0;
	r=n-1;
	printf("\nEnter array elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the key: ");
	scanf("%d",&key);
	loc=binary_search(a, l, r, key);
	printf("\nRequired location: %d", loc);
	return 0;
}
