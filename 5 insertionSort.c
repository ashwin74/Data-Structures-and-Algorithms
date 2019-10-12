#include <stdio.h>


void insertionSort(int arr[],int n);


int main()
{
	int n,i,j,temp,k;
	
	printf("enter the size of array\n");
	scanf("%d",&n);
	
	//read unsorted array
	int arr[n];
	printf("enter the number and press enter\n");
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	//insertion sort
	insertionSort(arr,n);
	
}


	//Insertion sort
	void insertionSort(int arr[],int n)
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		{
			j=i+1;
			while(j>0 && arr[j-1]>arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;			
			}
		}
		
		//Print sorted array
		printf("\n\nsorted array\n\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t", arr[i]);
		}
	}

