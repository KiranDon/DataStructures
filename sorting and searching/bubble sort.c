#include <stdio.h>
void bubbleSort(int arr[], int n)
{
	int i, j, temp;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main()
{
	int n, i;
	printf("Enter no. of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements: \n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nBefore sorting: \n");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	bubbleSort(arr, n);
	printf("\nAfter sorting: \n");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
