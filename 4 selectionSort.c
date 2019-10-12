#include <stdio.h>

//function prototype
int selectionSort(int arr[], int n);


int main()
{
	int n,i;
	
	printf("enter the size of array\n");
	scanf("%d",&n);
	
	//read unsorted array
	int arr[n];
	printf("enter the number and press enter\n");
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	selectionSort(arr,n);
}


//Selection sort

int selectionSort(int arr[], int n)
{
	int i,j,min,temp;
	for(j=0;j<n;j++)
	{
		min = j;
		for(i=j;i<n;i++)
		{
			if(arr[min]>arr[i+1])
			{
				min = i+1;
			}
		}
		temp = arr[j];
		arr[j] = arr[min];
		arr[min] = temp;
	}
	
	//Print sorted array
	printf("\n\nsorted array\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
}
