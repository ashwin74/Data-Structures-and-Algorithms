#include <stdio.h>

int main()
{
	int n,i,j,temp;
	
	printf("enter the size of array\n");
	scanf("%d",&n);
	
	//read unsorted array
	int arr[n];
	printf("enter the number and press enter\n");
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	//Bubble Sort
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	
	//Print sorted array
	for(i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
}
