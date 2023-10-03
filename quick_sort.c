#include <stdio.h>													//Header files

void printArray(int arr[], int n)									//Prints the Array
{
	for(int i = 0; i < n; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n");
}

void swap(int *x, int *y)											//Swaps two elements x and y.
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int low, int high) 						//Partitioning takes place.
{
    int pivot = arr[high];											//Pivot is our last element.
 
    int i = low;													//Pointer i -> to maintain the correct position where pivot has to be inserted.
 
    for (int j = low; j < high; j++) 								//Partition takes place.
	{
 
        if (arr[j] < pivot) 										//If the current element is less than the pivot element.
		{
            swap(&arr[i], &arr[j]); 								//Swap the current element with the i-th element.
			i++;													//Increment i.
        }
    }
    swap(&arr[i], &arr[high]); 										//Swap i-th element with the pivot element.
    return i; 														//Return the current position of the pivot in the array.
}
 
void quickSort(int arr[], int low, int high) 						//Quick sort is implemented.
{
    if (low < high) 												//If the array contains more than 1 elements.
	{	
        int pi = partition(arr, low, high);							//Partioning is first applied on the entire array.
 
        quickSort(arr, low, pi - 1);								//Quicksort is recursively applied to the left-subarray.
        quickSort(arr, pi + 1, high);								//Quicksort is recursively applied to the right-subarray.
    }
}

int main()
{
	int arr[] = {20, 1, 3, 12, 10, 0, 5};							//an array to work with.
	int n = sizeof(arr) / sizeof(arr[0]);							//size of the array

	printf("Array before sorting - ");
	printArray(arr, n);

	quickSort(arr, 0, n-1);											//quicksort is applied.

	printf("Array after sorting - ");
	printArray(arr, n);

	return 0;
}

//Average Case Complexity - O(N*Log(N))
//Worst Case Complexity - O(N**2)