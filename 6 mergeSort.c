#include <stdio.h>


//Functional prototype
void mergeSort(int arr[], int s, int e);
void merge(int arr[], int s, int mid, int midPlusOne, int e);

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
	
	//merge sort
	mergeSort(arr, 0, n-1);
	
	//print sorted array
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void mergeSort(int arr[], int s, int e)
{
	//Base Case - if 1 or 0 elements in array
	if(s>=e)
	{
		return;
	}
	else
	{
		// 1 - Divide
		int mid = (s+e)/2;
		
		// 2 - Recursively sort the array (s,mid) and (mid+1,e)
		mergeSort(arr,s,mid);
		mergeSort(arr,mid+1,e);
		
		// 3 - Merge the two arrays
		merge(arr,s,mid,mid+1,e);
	}
}


// Sorting in merge sort
void merge(int arr[], int s, int mid, int midPlusOne, int e)
{
	int i = s;
	int j = midPlusOne;
	int k = s;
	int temp[50];
	while(i<=mid && j<=e)
	{
		if(arr[i]<arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=e)
	{
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	//finally copy temp array to original array
	for(i=0;i<k;i++)
	{
		arr[i]=temp[i];
	}
}
