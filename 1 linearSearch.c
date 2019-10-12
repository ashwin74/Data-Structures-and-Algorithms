#include <stdio.h>

int main(void)
{
	int n, i, search;
	printf("Enter the number of elements in an array:\n");
	scanf("%d",&n);
	
	int arr[n];
	for (i=0;i<n;i++)
	{
		printf("enter %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("enter the number you want to search\n");
	scanf("%d",&search);
	
	for (i=0;i<n;i++)
	{
		if(arr[i]==search)
		{
			printf("your number %d is at %d\n",search,i+1);
			return;
		}
	}
	if (i==n)
	{
		printf("your number %d is unavailable in the array",search);
	}
}
