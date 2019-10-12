#include <stdio.h>

//Function Prototype
void binarySearch(int arr[],int n,int search);


//In binary search array should be sorted.
int main()
{
	int n,i,mid,search;
	
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++) 
	{
		printf("\nenter the elements %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\nenter the search number: ");
	scanf("%d",&search);
	
	binarySearch(arr,n,search);	
}

void binarySearch(int arr[],int n,int search)
{
	int start = 0;
	int end = n-1;
	int mid;
	
	while(start<=end)
	{
		mid = (start+end)/2;
		if(arr[mid]<search)
		{
			start = mid+1;
		} 
		else if (arr[mid]>search)
		{
			end = mid-1; 	
		}
		else if(arr[mid]==search)
		{
			printf("number found at %d\n",mid+1);
			return;
		}
	}
	if(start>end)
	{
		printf("not found\n");
	}
}
