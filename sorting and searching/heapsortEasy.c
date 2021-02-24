#include <stdio.h>

void heapSort(int arr[], int n)
{
	int i, temp;
	for(i=n/2; i>=0; i--)
	{
		heapify(arr, i, n);
	}
	//deleteing (swapping)
	for(i=n-1; i>=0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, 0, i);
	}
}

void heapify(int arr[],int i,int n)
{
	int temp, child;
	while(2*i+1 < n)
	{
		child = 2*i+1;
		if(arr[child+1] > arr[child] && child<n-1)
		{
			child += 1;
		}
		if(arr[child] > arr[i])
		{
			temp = arr[child];
			arr[child] = arr[i];
			arr[i] = temp;
		}
		i = child;
	}
}
int main()
{
	int n, i;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nBefore sorting:");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	heapSort(arr, n);
	printf("\nAfter sorting:");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
}
